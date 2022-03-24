#ifndef STACK_H
#define STACK_H

/*链式存储栈---实现*/
#include "llist.h"

typedef LLIST STACK;

STACK *Link_Storage_stack_create(int initsize);
int Link_Storage_stack_push(STACK *t_stack, const void *data);
int Link_Storage_stack_pop(STACK *t_stack, void *data);
void Link_Storage_stack_destory(STACK *t_stack);

#endif