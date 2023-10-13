#include "queue.h"

#include <stdio.h>

typedef struct {
	int value;
	struct QueueNode* next;
} QueueNode;

typedef struct {
	struct QueueNode* head;
	struct QueueNode* back;
} Queue;

void printQueue(Queue** queue)
{
    QueueNode* current = (*queue)->back;
    while (current != NULL)
    {
        int value = current->value;
        printf("%d\n", value);
        QueueNode* current = current->next;
    } 
}
