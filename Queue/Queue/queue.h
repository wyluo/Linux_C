#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

typedef int Datatype;
#define datasize 16

typedef struct Queue_Node_st
{
	Datatype data[datasize];
	int head;
	int tail;
}queue;

queue* Create();
static bool queue_Is_empty(queue* t_queue);
static bool queue_Is_fully(queue* t_queue);
int Enter_queue(queue *t_queue, Datatype *data);
int Exit_queue(queue* t_queue, Datatype* data);
void Travel_queue(queue *t_queue);
void Clear_queue(queue* t_queue);
void Destory(queue *t_queue);

#endif
