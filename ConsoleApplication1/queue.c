#include "queue.h"
#include <stdlib.h>
#include <stdbool.h>

void enqueue(Queue* const queue, const int value)
{
	QueueNode* next = malloc(sizeof(QueueNode));
	next->value = value;
	next->next = NULL;
	QueueNode* head = queue->head;
	head->next = next;
	head = next;
}

void dequeue(Queue* queue)
{
	QueueNode* back = queue->back;
	QueueNode* next = back->next;
	queue->back = next;
	free(back);
}

bool isEmpty(Queue* queue)
{
	return queue->head == NULL && queue;
}
