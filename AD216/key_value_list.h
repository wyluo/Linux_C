#ifndef KEY_VALUE_LIST_H
#define KEY_VALUE_LIST_H

#include "types.h"

/* !brief Opaque type for a key-value list object. */
typedef struct key_value_list_tag *key_value_list_t;//结构体指针

/*! \brief Create a key-value list.

    Creates an empty key-value list and returns an opaque
    handle to it.

    \return A handle to a key-value list or 0 if it fail.
*/
key_value_list_t KeyValueList_Create(void);

/*! \brief Destory a key-value list.

    If #list contains any key-value pairs they will all be removeand
    any menory they own will be freed.

    \param list Key-value list to destory.
*/
void KeyValueList_Destory(key_value_list_t *list);

/*! \brief Remove all key-value pairs from a key-value list.

    Any memory owned by a key-value pair will be freed when it is removed.

    \param list Key-value list to remove all key-value pairs from.
*/
void KeyValueList_RemoveAll(key_value_list_t list);


#endif