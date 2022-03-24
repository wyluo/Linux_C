#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include "llist.h"

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

/*
 *链式存储
 */
typedef LLIST QUEUE;

QUEUE *Link_Storage_Create(int initsize);
int Link_Storage_Enter_queue(QUEUE *ptr, const void *data);
int Link_Storage_Exit_queue(QUEUE *ptr, void *data);
void Link_Storage_Destory_queue(QUEUE *ptr);

#endif
