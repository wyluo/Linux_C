#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

int main(int argc, char *argv[])
{
    sqstack *t_sqstack = NULL;
    Datatype arry[] = {11, 85, 5, 23};
    int i = 0;

    t_sqstack = stack_create();
    if(t_sqstack == NULL)
    {
        return 0;
    }

    for(i = 0; i < sizeof(arry)/sizeof(*arry); i++)
    {
        stack_push(t_sqstack, &arry[i]);
    }

    stack_travel(t_sqstack);

    printf("now doing stack pop operation\n");
    for(i = 0; i < sizeof(arry)/sizeof(*arry); i++)
    {
        stack_pop(t_sqstack, &arry[i]);
        stack_travel(t_sqstack);
    }
    stack_travel(t_sqstack);

    stack_destory(t_sqstack);

    return 0;
}