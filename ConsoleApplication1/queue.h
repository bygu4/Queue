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

bool isEmpty(Queue* const queue);
void enqueue(Queue* const queue, const int value);
void dequeue(Queue* const queue);
int front(Queue *queue);
int back(Queue *queue);
void printQueue(Queue* queue);
  

typedef enum ErrorCode {
	ok,
	TestNotPassed,
	NullTestNotPassed,
	WrongAnswerOnNotEmptyQueue,
	WrongAnswerOnEmptyQueue,
	DoesntAddElements,
	IncorrectOrder
} ErrorCode;

bool test(void);