#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "queue.h"

/*
 *note: empty condiction is : head == tail
 *      fully condiction is : (t+1) % datasize == head
 */

queue* Create()
{
    queue *new_queue = NULL;

    new_queue = malloc(sizeof(*new_queue));
    if(new_queue == NULL)
    {
        return NULL;
    }

    new_queue->head = 0;
    new_queue->tail = 0;

    return new_queue;
}

#if 1
static bool queue_Is_empty(queue* t_queue)
{
    return (t_queue->head == t_queue->tail);
}

static bool queue_Is_fully(queue* t_queue)
{
    return ((t_queue->tail + 1) % datasize == t_queue->head);
}
#endif

int Enter_queue(queue *t_queue, Datatype *data)
{
    //firstly need to judge queue fully or not
    if((t_queue->tail + 1) % datasize == t_queue->head)
    {
        return -1;//not allow enter queue
    }

    printf("%s---%d\n", __FILE__, __LINE__);

#if 1
    if(queue_Is_fully(t_queue))
        return -1;
#endif

    t_queue->tail = (t_queue->tail + 1) % datasize;//防止数组越界
    t_queue->data[t_queue->tail] = *data;
    return 0;
}

int Exit_queue(queue* t_queue, Datatype* data)
{
    if (queue_Is_empty(t_queue))
        return -1;

    t_queue->head = (t_queue->head + 1) % datasize;
    *data = t_queue->data[t_queue->head];
    return 0;
}

void Travel_queue(queue *t_queue)
{
    int value = 0;

    //firstly judge queue is empty or not
    if(t_queue->head == t_queue->tail)
    {
        printf("this queue is empty no data need exit queue\n");
        return;//not need travel current queue
    }

#if 1
    if(queue_Is_empty(t_queue))
        return;
#endif

    //printf("%s---%d\n", __FILE__, __LINE__);

    value = (t_queue->head + 1) % datasize;//防止数组越界
    while(value != t_queue->tail)
    {
        printf("%d-->", t_queue->data[value]);
        value = (value + 1) % datasize;//防止数组越界
    }
    printf("%d\n", t_queue->data[value]);//now value == t_queue->tail
}

void Clear_queue(queue* t_queue)
{
    t_queue->head = t_queue->tail;
}

void Destory(queue *t_queue)
{
    free(t_queue);
}

