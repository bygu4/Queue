#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int value;
    struct QueueNode* next;
} QueueNode;

struct Queue {
    struct QueueNode* head;
    struct QueueNode* back;
};

Queue* createQueue(void)
{
    Queue* queue = malloc(sizeof(Queue));
    if (queue == NULL)
    {
        return NULL;
    }
    queue->head = NULL;
    queue->back = NULL;
    return queue;
}

bool isEmpty(const Queue* const queue)
{
    return queue->head == NULL;
}

bool enqueue(Queue* const queue, const int value)
{
    QueueNode* next = malloc(sizeof(QueueNode));
    if (next == NULL)
    {
        return true;
    }
    next->value = value;
    next->next = NULL;
    if (isEmpty(queue))
    {
        queue->head = next;
        queue->back = next;
        return false;
    }
    QueueNode* head = queue->head;
    head->next = next;
    head = next;
    return false;
}

void dequeue(Queue* const queue)
{
    if (isEmpty(queue))
    {
        return;
    }
    QueueNode* back = queue->back;
    QueueNode* next = back->next;
    free(back);
    if (queue->back == queue->head)
    {
        queue->head = next;
    }
    queue->back = next;
}

int front(const Queue* const queue)
{
    QueueNode *head = queue->head;
    if (head == NULL)
    {
        return NULL;
    }
    return head->value;
}

int back(const Queue* const queue)
{
    QueueNode *back = queue->back;
    if (back == NULL)
    {
        return NULL;
    }
    return back->value;
}

void printQueue(const Queue* const queue)
{
    QueueNode* current = (queue)->back;
    while (current != NULL)
    {
        int value = current->value;
        printf("%d\n", value);
        current = current->next;
    } 
}

void freeQueue(Queue** const queue)
{
    while (!isEmpty(*queue))
    {
        dequeue(*queue);
    }
    free(*queue);
    *queue = NULL;
}
