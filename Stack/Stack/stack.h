#ifndef STACK_H
#define STACK_H

#define MAXSIZE 32

typedef int Datatype;

typedef struct node_st
{
    Datatype data[MAXSIZE];
    int top;
}sqstack;

sqstack *stack_create(void);
int stack_Is_empty(sqstack *t_sqstack);
int stack_push(sqstack *t_sqstack, Datatype *data);
void stack_travel(sqstack *t_sqstack);
int stack_pop(sqstack *t_sqstack, Datatype *data);
int stack_Read_topValue(sqstack *t_sqstack, Datatype *data);
void stack_destory(sqstack *t_sqstack);


#endif