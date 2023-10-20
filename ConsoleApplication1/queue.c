#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

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

bool isEmpty(Queue* const queue)
{
    return queue->head == NULL && queue->back == NULL;
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

int front(Queue* const queue)
{
    QueueNode *head = queue->head;
    if (head == NULL)
    {
        return NULL;
    }
    return head->value;
}

int back(Queue* const queue)
{
    QueueNode *back = queue->back;
    if (back == NULL)
    {
        return NULL;
    }
    return back->value;
}

void printQueue(Queue* const queue)
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
}
