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