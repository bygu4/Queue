#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "queue.h"

int main()
{
	Queue *queue = malloc(sizeof(Queue));
	queue->back = NULL;
	queue->head = NULL;
	enqueue(queue, 1);
	enqueue(queue, 2);
}

