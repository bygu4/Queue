#include "queue.h"
#include <stdlib.h>
#include <stdbool.h>

void enqueue(Queue *const queue, const int value)
{
    QueueNode *next = malloc(sizeof(QueueNode));
    next->value = value;
    next->next = NULL;
    QueueNode *head = queue->head;
    head->next = next;
    head = next;
}

void dequeue(Queue *queue)
{
    QueueNode *back = queue->back;
    QueueNode *next = back->next;
    queue->back = next;
    free(back);
}

bool isEmpty(Queue *queue)
{
    return queue->head == NULL && queue;
}

int front(Queue *queue)
{
    QueueNode *head = queue->head;
    if (head == NULL)
    {
        return NULL;
    }
    return head->value;
}

int back(Queue *queue)
{
    QueueNode *back = queue->back;
    if (back == NULL)
    {
        return NULL;
    }
    return back->value;
}

void printQueue(Queue *queue)
{
    QueueNode *current = (queue)->back;
    while (current != NULL)
    {
        int value = current->value;
        printf("%d\n", value);
        QueueNode *current = current->next;
    }
}

bool test(void)
{
    int errorCodeFront = testFront();
}

ErrorCode testFront(void)
{
    Queue *queue = malloc(sizeof(Queue));
    enqueue(queue, 1);
    enqueue(queue, 2);

    if (front(queue) != 2)
    {
        // deleteQueue();
        return TestNotPassed;
    }

    Queue *queue = malloc(sizeof(Queue));
    queue->back = NULL;
    queue->head = NULL;

    if (front(queue) != NULL)
    {
        // deleteQueue();
        return NullTestNotPassed;
    }

    return ok;
}

ErrorCode testBack(void)
{
    Queue *queue = malloc(sizeof(Queue));
    queue->back = NULL;
    queue->head = NULL;
    enqueue(queue, 1);
    enqueue(queue, 2);

    if (front(queue) != 1)
    {
        // deleteQueue();
        return TestNotPassed;
    }

    Queue *queue = malloc(sizeof(Queue));
    queue->back = NULL;
    queue->head = NULL;

    if (front(queue) != NULL)
    {
        // deleteQueue();
        return NullTestNotPassed;
    }

    return ok;
}

ErrorCode testIsEmpty(void)
{
    Queue *queue = malloc(sizeof(Queue));
    queue->back = NULL;
    queue->head = NULL;
    enqueue(queue, 1);
    enqueue(queue, 2);
    if (isEmpty(queue))
    {
        // deleteQueue();
        return WrongAnswerOnNotEmptyQueue;
    }

    Queue *queue = malloc(sizeof(Queue));
    queue->back = NULL;
    queue->head = NULL;
    if (!isEmpty(queue))
    {
        // deleteQueue();
        return WrongAnswerOnEmptyQueue;
    }

    return ok;
}

ErrorCode testEnque(void)
{
    Queue *queue = malloc(sizeof(Queue));
    queue->back = NULL;
    queue->head = NULL;
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);

    if (isEmpty(queue))
    {
        // deleteQueue();
        return DoesntAddElements;
    }

    Queue *queue = malloc(sizeof(Queue));
    queue->back = NULL;
    queue->head = NULL;
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);

    int array[3] = {1, 2, 3};
    QueueNode *current = queue->back;
    for (int i = 0; i < 3; ++i)
    {
        int value = current->value;
        if (array[i] != value)
        {
            return IncorrectOrder;
        }
        current = current->next;
    }
}

bool testDequeue(void)
{
    Queue *queue = malloc(sizeof(Queue));
    queue->back = NULL;
    queue->head = NULL;
    enqueue(queue, 1);
    enqueue(queue, 2);
    


}



