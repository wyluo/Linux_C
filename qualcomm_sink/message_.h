#ifndef __MESSAGE__H_
#define __MESSAGE__H_

#include "types.h"

#define D_IMMEDIATE ((Delay) - 1)

typedef uint16 MessageId;

typedef const void *Message;

typedef uint32 Delay;

typedef struct TaskData *Task;

typedef struct TaskData { void (*handler)(Task, MessageId, Message);} TaskData;

#endif