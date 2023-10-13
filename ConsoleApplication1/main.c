#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main()
{
	Queue* queue = malloc(sizeof(Queue));
	queue->back = NULL;
	queue->head = NULL;
	enqueue(queue, 1);
	enqueue(queue, 2);
	printf("%d", queue->head->value);
}