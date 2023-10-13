#include "queue.h"

typedef struct {
	int value;
	struct QueueNode* next;
} QueueNode;

typedef struct {
	struct QueueNode* head;
	struct QueueNode* back;
} Queue;
