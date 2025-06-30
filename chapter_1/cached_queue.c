#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cached_queue.h"

void CachedQueue_Init(CachedQueue *const me, char* fName,
	int (*isFullFunction)(CachedQueue* const me),
	int (*isEmptyFunction)(CachedQueue* const me),
	int (*getSizeFunction)(CachedQueue* const me),
	int (*insertFunction)(CachedQueue* const me, int k),
	int (*removeFunction)(CachedQueue* const me),
	void (*flushFunction)(CachedQueue* const me),
	void (*loadFunction)(CachedQueue* const me)
) {
	/* initialize base class */
	me->queue = Queue_Create(); /* queue member must use its original functions */
	/* initialize subclass attributes */
	me->numberElementsOnDisk = 0;
	strcpy(me->filename,fName);
	/* initialize aggregates */
	me->outputQueue = Queue_Create();
	/* initialize subclass virtual operation pointers */
	me->isFull = isFullFunction;
	me->isEmpty = isEmptyFunction;
	me->getSize = getSizeFunction;
	me->insert = insertFunction;
	me->remove = removeFunction;
	me->flush = flushFunction;
	me->load = loadFunction;
}

void CachedQueue_Cleanup(CachedQueue *const me) {
	Queue_Cleanup(me->queue);
}

int CachedQueue_IsFull(CachedQueue *const me) {
	return me->queue->isFull(me->queue) && me->outputQueue->isFull(me->outputQueue);
}

int CachedQueue_IsEmpty(CachedQueue *const me) {
	return me->queue->isEmpty(me->queue) && me->outputQueue->isEmpty(me->outputQueue) && (me->numberElementsOnDisk == 0);
}

int CachedQueue_getSize(CachedQueue *const me) {
	return me->queue->getSize(me->queue) + me->outputQueue->getSize(me->outputQueue) + me->numberElementsOnDisk;
}

void CachedQueue_Insert(CachedQueue *const me, int k) {
	//Insert algorithm:
	//If the queue is full, call flush to write out the queue to disk and reset the queue
	//end if
	//Insert the data into the queue
	if(me->queue->isFull(me->queue)) 
		me->flush(me);
	me->queue->insert(me->queue,k);
}

int CachedQueue_Remove(CachedQueue *const me) {
	//Remove algorithm:
	//If there is data in the outputQueue, remove it from the outputQueue
	//else if there is data on disk, call load to bring it into the outputQueue, remove it from the outputQueue
	//else if there is data in the queue, remove it from there
	//(if there is no data to remove then return sentinel value)
	if (!me->outputQueue->isEmpty(me->outputQueue))
		return me->outputQueue->remove(me->outputQueue);
	else if (me->numberElementsOnDisk > 0) {
		me->load(me);
		return me->queue->remove(me->queue);
	} else {
		return me->queue->remove(me->queue);
	}
}

void CachedQueue_Flush(CachedQueue *const me) {
	//Precondition: this is called only when queue is full and filename is valid
	//Flush algorthm:
	//If file is not open, then open file
	//While not queue->isEmpty()
	//queue->remove();
	//Write data to disk
	//numberElementsOnDisk++
	//end while

	//Write file I/O statements here...
}

void CachedQueue_Load(CachedQueue *const me) {
	//Precondition: this is called only when outputQueue is empty and filename is valid
	//Load algorithm:
	//while(!outputQueue->isFull() && (numberElementsOnDisk > 0)
	//read from start of file (i.e., oldest datum)
	//numberElementsOnDisk--;
	//outputQueue->insert();
	//end while

	//Write file I/O statements here...
}

CachedQueue *CachedQueue_Create(void) {
	CachedQueue *me = (CachedQueue *)malloc(sizeof(CachedQueue));
	if (me != NULL) {
		CachedQueue_Init(me,"C:\\queuebuffer.dat", CachedQueue_IsFull, CachedQueue_IsEmpty,
			CachedQueue_getSize, CachedQueue_Insert, CachedQueue_Remove, CachedQueue_Flush,
			CachedQueue_Load);
	}

	return me;
}

void CachedQueue_Destroy(CachedQueue *const me) {
	if (me != NULL) {
		CachedQueue_Cleanup(me);
	}

	free(me);
}

