#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "global.h"

STACK *Link_Storage_stack_create(int initsize)
{
    return llist_create(initsize);
}

int Link_Storage_stack_push(STACK *t_stack, const void *data)
{
    return llist_insert(t_stack, data, LLIST_FORWARD);
}

int Link_Storage_stack_pop(STACK *t_stack, void *data)
{
    return llist_fetch(t_stack, (void *)0, always_match, data);
}

void Link_Storage_stack_destory(STACK *t_stack)
{
    llist_destory(t_stack);
}