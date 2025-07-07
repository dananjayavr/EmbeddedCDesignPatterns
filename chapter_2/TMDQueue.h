#ifndef TMDQueue_H
#define TMDQueue_H

/* auto generated */
#include <stdio.h>
#include "ECPkg.h"
#include "TimeMarkedData.h"

typedef struct TMDQueue TMDQueue;

/* this queue is mean to operate as a "leaky" queue. In this queue, data are never
   removed per se, but are instead overwritten when the buffer pointer wraps around.
   This allows for many clients to read the same data from the queue */
struct TMDQueue {
	int head;
	int size;
	struct TimeMarkedData buffer[QUEUE_SIZE];
};

void TMDQueue_Init(TMDQueue* const me);
void TMDQueue_Cleanup(TMDQueue* const me);

/* operations */
int TMDQueue_getNextIndex(TMDQueue *const me, int index);
void TMDQueue_insert(TMDQueue *const me, const struct TimeMarkedData tmd);
boolean TMDQueue_isEmpty(TMDQueue *const me);

TMDQueue *TMDQueue_Create(void);
void TMDQueue_Destory(TMDQueue *const me);

#endif