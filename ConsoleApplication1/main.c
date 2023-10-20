#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	Queue* queue = createQueue();
	if (queue == NULL)
	{
		printf("An error occured");
		return -1;
	}
	queue->back = NULL;
	queue->head = NULL;
	enqueue(queue, 1);
	printf("%d\n", back(queue));
	enqueue(queue, 2);
	printQueue(queue);
	dequeue(queue);
	printf("front: %d\n", front(queue));
	printf("back: %d\n", back(queue));
	dequeue(queue);
	printf(isEmpty(queue) ? "correct" : "incorrect");
	freeQueue(&queue);
}
