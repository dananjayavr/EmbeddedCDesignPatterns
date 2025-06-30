#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void Queue_Init(Queue *const me, 
	int (*isFullFunction)(Queue *const me),
	int (*isEmptyFunction)(Queue *const me),
	int (*getSizeFunction)(Queue *const me),
	void (*insertFunction)(Queue *const me, int k),
	int (*removeFunction)(Queue *const me)) {

	/* Initialize attributes */
	me->head = 0;
	me->tail = 0;
	me->size = 0;

	/* Initialize member function pointers */
	me->isFull = isFullFunction;
	me->isEmpty = isEmptyFunction;
	me->getSize = getSizeFunction;
	me->insert = insertFunction;
	me->remove = removeFunction;
}

void Queue_Cleanup(Queue *const me) {

}

int Queue_IsFull(Queue *const me) {
	return (me->head + 1) % QUEUE_SIZE == me->tail;
}

int Queue_IsEmpty(Queue *const me) {
	return (me->head == me->tail); 
}

int Queue_getSize(Queue *const me) {
	return me->size;
}

void Queue_Insert(Queue *const me, int k) {
	if(!me->isFull(me)) {
		me->buffer[me->head] = k;
		me->head = (me->head + 1) % QUEUE_SIZE;
		++me->size;
	}
}

int Queue_Remove(Queue *const me) {
	int value = -9999; //Sentinal value
	if(!me->isEmpty(me)) {
		value = me->buffer[me->tail];
		me->tail = (me->tail + 1) % QUEUE_SIZE;
		--me->size;
	}

	return value;
}

Queue *Queue_Create(void) {
	Queue *me = (Queue *)malloc(sizeof(Queue));
	if (me != NULL) {
		Queue_Init(me,Queue_IsFull,Queue_IsEmpty,Queue_getSize,Queue_Insert,Queue_Remove);
	}

	return me;
}

void Queue_Destroy(Queue *const me) {
	if (me != NULL) {
		Queue_Cleanup(me);
	}

	free(me);
}