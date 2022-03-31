#ifndef KEY_VALUE_LIST_H
#define KEY_VALUE_LIST_H

#include "types.h"
#include <stdbool.h>

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

/*! \brief Check if a key is set in a key-value list.

    \param list Key-value list to search in.
    \param key Key to search for.

    \return bool TRUE if key exists; FALSE otherwise.
*/
static bool KeyValueList_IsSet(key_value_list_t list, key_value_list_t key);

/*! \brief Get the value (with an expected size) for a key in a key-value list.

    The value is returned as a pointer to the buffer owned by the key-value
    pair.

    If the key does not exist the pointer to the buffer will not be modified.

    The function will panic if an item with the same key is found with a size
    different to the size specified.

    \param[in] list Key-value list to search in.
    \param[in] key Key to search for.
    \param[in] size The expected size of the key value.

    \return value The pointer to the key's value, or NULL is not found.

    \note This function should be used in preference to KeyValueList_Get if
    the size of the object is known.
*/
static bool KeyValueList_Get(key_value_list_t list, key_value_list_t key, void **value_p, size_t *size_p)

/*! \brief Add a key-value pair to a key-value list.

    This function will add the new key-value pair to the given list unless the
    key is already in the list or the list is full.

    The data passed in via #value is copied to the list and if necessary a new
    buffer will be allocated and owned by the list to store the copied data.
    If the buffer cannot be allocated this function will panic.

    Small values of 4 octets or less will not required a buffer to be allocated
    by the list to store the copied data.

    \param list Key-value list to add to.
    \param key Key to insert.
    \param value Pointer to the data to associate with the key.
    \param size Size in octets of the data pointed to by value.

    \return bool TRUE if key-value was added successfully; FALSE otherwise.
*/
bool KeyValueList_Add(key_value_list_t list, key_value_list_t key, const void *value, size_t size);

#endif