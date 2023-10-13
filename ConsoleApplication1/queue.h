#pragma once

typedef struct {
	int value;
	struct QueueNode* next;
} QueueNode;

typedef struct {
	struct QueueNode** head;
	struct QueueNode** back;
} Queue;

void enqueue(Queue** const queue, const int value);
void dequeue(Queue** const queue);
