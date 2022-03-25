#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "llist.h"

LLIST *llist_create(int initsize)
{
    LLIST *newptr = NULL;
    newptr = malloc(sizeof(*newptr));
    if(newptr == NULL)
    {
        return NULL;
    }

    newptr->size = initsize;
    newptr->head.data = NULL;
    newptr->head.prev = &newptr->head;
    newptr->head.next = &newptr->head;

    return newptr;
}

int llist_insert(LLIST *ptr, const void *data, int mode)
{
    struct llist_node_st *newnode = NULL;

    newnode = malloc(sizeof(*newnode));
    if(newnode == NULL)
    {
        return -1;
    }

    newnode->data = malloc(ptr->size);
    if(newnode->data == NULL)
    {
        return -2;
    }

    memcpy(newnode->data, data, ptr->size);

    if(mode == LLIST_FORWARD)
    {
        newnode->prev = &ptr->head;
        newnode->next = ptr->head.next;
    }
    else if(mode == LLIST_BACKWARD)
    {
        newnode->prev = ptr->head.prev;
        newnode->next = &ptr->head;
    }
    else
    {
        return -3;
    }
    newnode->prev->next = newnode;
    newnode->next->prev = newnode;

    return 0;
}

static struct llist_node_st *find_(LLIST *ptr, const void *key, llist_cmp *cmp)
{
    struct llist_node_st *current_node = NULL;

    for(current_node = ptr->head.next; current_node != &ptr->head; current_node = current_node->next)
    {
        if(cmp(key, current_node->data) == 0)
            break;
    }

    return current_node;
}

int llist_fetch(LLIST *ptr, const void *key, llist_cmp* cmp, void *data)
{
    struct llist_node_st *node = NULL;

    node = find_(ptr, key, cmp);
    if(node == &ptr->head || node == NULL)
    {
        return -1;
    }

    node->prev->next = node->next;
    node->next->prev = node->prev;

    if(data != NULL)
    {
        memcpy(data, node->data, ptr->size);
    }

    free(node->data);
    free(node);

    return 0;
}

void llist_destory(LLIST *ptr)
{
    struct llist_node_st *curnode = NULL, *nextnode = NULL;
    for(curnode = ptr->head.next; curnode != &ptr->head; curnode = nextnode)
    {
        nextnode = curnode->next;
        free(curnode->data);
        free(curnode);
    }
    free(ptr);
}