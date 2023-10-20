#pragma once
#include <stdbool.h>

typedef struct Queue Queue;

Queue* createQueue(void);
bool isEmpty(const Queue* const queue);
bool enqueue(Queue* const queue, const int value);
void dequeue(Queue* const queue);
int front(const Queue* const queue);
int back(const Queue* const queue);
void printQueue(const Queue* const queue);
void freeQueue(Queue** const queue);
  

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
