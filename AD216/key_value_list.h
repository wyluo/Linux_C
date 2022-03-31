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


#endif