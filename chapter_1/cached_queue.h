#ifndef _CACHED_QUEUE_H
#define _CACHED_QUEUE_H

#include "queue.h"

typedef struct CachedQueue CachedQueue;

struct CachedQueue {
	Queue *queue; /* base class */
	/* new attributes */
	char filename[80];
	int numberElementsOnDisk;
	/* aggregation in subclass */
	Queue *outputQueue;
	/* inherited virtual functions */
	int (*isFull)(CachedQueue* const me);
	int (*isEmpty)(CachedQueue* const me);
	int (*getSize)(CachedQueue* const me);
	int (*insert)(CachedQueue* const me, int k);
	int (*remove)(CachedQueue* const me);
	/* new virtual functions */
	void (*flush)(CachedQueue *const me);
	void (*load)(CachedQueue *const me);
};

/* constructors and destructors */
void CachedQueue_Init(CachedQueue *const me, char* fName,
	int (*isFullFunction)(CachedQueue* const me),
	int (*isEmptyFunction)(CachedQueue* const me),
	int (*getSizeFunction)(CachedQueue* const me),
	int (*insertFunction)(CachedQueue* const me, int k),
	int (*removeFunction)(CachedQueue* const me),
	int (*flushFunction)(CachedQueue* const me),
	int (*loadFunction)(CachedQueue* const me)
);

void CachedQueue_Cleanup(CachedQueue *const me);

/* operations */
int CachedQueue_isFull(CachedQueue* const me);
int CachedQueue_isEmpty(CachedQueue* const me);
int CachedQueue_getSize(CachedQueue* const me);
int CachedQueue_insert(CachedQueue* const me, int k);
int CachedQueue_remove(CachedQueue* const me);
int CachedQueue_flush(CachedQueue* const me);
int CachedQueue_load(CachedQueue* const me);

CachedQueue *CachedQueue_Create(void);

void CachedQueue_Destroy(CachedQueue *const me);

#endif