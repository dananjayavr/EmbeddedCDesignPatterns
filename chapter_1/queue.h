#ifndef _QUEUE_H
#define _QUEUE_H

#define QUEUE_SIZE 10

/* Class Queue */
typedef struct Queue Queue;

struct Queue {
	int buffer[QUEUE_SIZE];
	int head;
	int size;
	int tail;
	int(*isFull)(Queue *const me);
	int(*isEmpty)(Queue *const me);
	int(*getSize)(Queue *const me);
	void(*insert)(Queue *const me, int k);
	int(*remove)(Queue *const me);
};

/* constructors & destructors */
void Queue_Init(Queue *const me, int (*isFullFunction)(Queue *const me),
int (*isEmptyFunction)(Queue *const me),

int (*getSizeFunction)(Queue *const me),

void (*insertFunction)(Queue *const me, int k),

int (*removeFunction)(Queue *const me));

void Queue_Cleanup(Queue *const me);

/* Operations */
int Queue_isFull(Queue *const me);
int Queue_isEmpty(Queue *const me);
int Queue_getSize(Queue *const me);
void Queue_insert(Queue *const me, int k);
int Queue_remove(Queue *const me);
Queue *Queue_Create(void);
void Queue_Destroy(Queue *const me);

#endif