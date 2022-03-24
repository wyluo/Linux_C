#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

sqstack *stack_create(void)
{
    sqstack *t_sqstack = NULL;

    t_sqstack = malloc(sizeof(*t_sqstack));
    if(t_sqstack == NULL)
    {
        return NULL;
    }

    t_sqstack->top = -1;//means this stack do not have value
    return t_sqstack;
}

/*
 *if return value == 1, this stack is empty
 */
int stack_Is_empty(sqstack *t_sqstack)
{
    return (t_sqstack->top == -1);
}

int stack_push(sqstack *t_sqstack, Datatype *data)
{
    if(t_sqstack->top == (MAXSIZE - 1))
    {
        return -1;
    }

    t_sqstack->data[++t_sqstack->top] = *data;
    return 0;
}

int stack_pop(sqstack *t_sqstack, Datatype *data)
{
    if(stack_Is_empty(t_sqstack))
    {
        return -1;
    }

    *data = t_sqstack->data[t_sqstack->top--];

    return 0;
}

int stack_Read_topValue(sqstack *t_sqstack, Datatype *data)
{
    if(stack_Is_empty(t_sqstack))
    {
        return -1;
    }

    *data = t_sqstack->data[t_sqstack->top];

    return 0;
}

void stack_travel(sqstack *t_sqstack)
{
    int i = 0;

    if (stack_Is_empty(t_sqstack))
    {
        printf("%s---%d---now stack is empty\n", __FILE__, __LINE__);
        return;
    }

    for(i = 0; i <= t_sqstack->top; i++)
        printf("%d--", t_sqstack->data[i]);
    printf("\n");
}

void stack_destory(sqstack *t_sqstack)
{
    free(t_sqstack);
}