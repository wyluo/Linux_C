#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "key_value_list.h"

/*! The linked list of elements that do not fit into 32 bits */
typedef struct large_kv_element_t
{
    struct large_kv_element_t *next;
    uint16 len;
    uint16 key;
    uint8 data[1];
}large_kv_element_t;

/*! Structure to store key/value data. Types <= 32 bits are stroed in dynamic
    fixed-type arrays. Types > 32 bits are stored in a linked list. */
struct key_value_list_tag
{
    /*! Length of dynamic keys array */
    uint8 len_keys;

    /*! Length of dynamic values8 array */
    uint8 len8;

    /*! Lenght of dynamic values16 array */
    uint8 len16;

    /*! Length of dynamic values32 array */
    uint8 len32;

    /* Pointer to arrays of keys. */
    uint16 *keys;

    /* Pointer to array of uint8s. */
    uint8 *values8;

    /* Pointer to array of uint16s */
    uint16 *values16;

    /* Pointers to arrays of uint32/ptr */
    uint32 *values32;

    /* Linked list of larger elements */
    large_kv_element_t *head;
};

key_value_list_t KeyValueList_Create(void)
{
    size_t size = sizeof(struct key_value_list_tag);//将结构体的大小赋值
    key_value_list_t list = PanicUnlessMalloc(size);
    memset(list, 0, size);//初始化list
    return list;
}

void KeyValueList_Destory(key_value_list_t *list)
{
    PanicNull(list);
    KeyValueList_RemoveAll(*list);
    free(*list);
    *list = NULL;
}

void KeyValueList_RemoveAll(key_value_list_t list)
{
    large_kv_element_t *head = list->head;
    while(head)//直到将链表都释放，退出循环
    {
        large_kv_element_t *tmp = head;
        head = head->next;
        free(tmp);
    }
    //将结构体中的成员都释放
    free(list->keys);
    free(list->values8);
    free(list->values16);
    free(list->values32);
    memset(list, 0, sizeof(*list));//初始化结构体
}

static bool KeyValueList_Get(key_value_list_t list, key_value_key_t key, void **value_p, size_t *size_p)
{
    unsigned index;
    uint16 *keys;
    large_kv_element_t *ele;

    PanicNull(list);
    PanicNull(value_p);
    PanicNull(size_p);

    for(ele = list->head; ele != NULL; ele = ele->next)//链表遍历，使用next指针
    {
        if(ele->key == key)
        {
            *size_p = ele->len;
            *value_p = ele->data;
            return TRUE;
        }
    }

    keys = list->keys;

    for(index = 0; index < list->len_keys; index++)
    {
        if(*keys++ == key)
        {
            if(index < list->len8)
            {
                *size_p = sizeof(uint8);
                *value_p = (void*)(list->values8 + index);
                return TRUE;
            }

            index -= list->len8;
            if(index < list->len16)
            {
                *size_p = sizeof(uint16);
                *value_p = (void*)(list->values16 + index);
                return TRUE;
            }

            index -= list->len16;
            *size_p = sizeof(uint32);
            *value_p = (void*)(list->values32 + index);
            return TRUE;
        }
    }
    return FALSE;
}

static bool KeyValueList_IsSet(key_value_list_t list, key_value_key_t key)
{
    size_t size;
    void *addr;
    return KeyValueList_Get(list, key, &addr, &size);
}

bool KeyValueList_Add(key_value_list_t list, key_value_key_t key, const void *value, size_t size)
{
    bool success = FALSE;

    PanicNull(list);

    if(!KeyValueList_IsSet(list, key))
    {
        success = keyValueList_addKeyValuePair(list, key, value, size);
    }
    return success;
}




