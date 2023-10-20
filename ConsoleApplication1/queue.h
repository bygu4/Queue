#pragma once
#include <stdbool.h>

typedef struct {
	int value;
	struct QueueNode* next;
} QueueNode;

typedef struct {
	struct QueueNode* head;
	struct QueueNode* back;
} Queue;

Queue* createQueue(void);
bool isEmpty(Queue* const queue);
bool enqueue(Queue* const queue, const int value);
void dequeue(Queue* const queue);
int front(Queue* const queue);
int back(Queue* const queue);
void printQueue(Queue* const queue);
void freeQueue(const Queue** const queue);
