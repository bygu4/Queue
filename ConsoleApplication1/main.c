#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "queue.h"

int main(void)
{

	Queue* queue = createQueue();
	if (queue == NULL)
	{
		printf("An error occured");
		return -1;
	}

	enqueue(queue, 1);
	printf("%d\n", back(queue));
	enqueue(queue, 2);

	printQueue(queue);
	dequeue(queue);
	printf("front: %d\n", front(queue));
	printf("back: %d\n", back(queue));
	dequeue(queue);
	printf(isEmpty(queue) ? "correct\n" : "incorrect\n");
	enqueue(queue, 8);
	printQueue(queue);
	freeQueue(&queue);
}
