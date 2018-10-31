#include "linked_queue.h"
#include <stdio.h>
#include <stdlib.h>

/*
struct QueueNode
{
    ElemType data;
    struct QueueNode *next;
};

struct Queue
{
    struct QueueNode *front;
    struct QueueNode *rear;
};
*/

Status InitQueue(struct Queue **q)
{
    (*q) = (struct Queue*)malloc(sizeof(struct Queue));
    (*q)->front = (*q)->rear = NULL;
    return OK;
}

Status QueueEmpty(struct Queue* q)
{
    if (!q->front && !q->rear)
        return TRUE;
    return FALSE;
}

int QueueLength(struct Queue *q)
{
    int n = 0;
    if (!q->front && !q->rear)
        return n;
    struct QueueNode* node;
    node = q->front;
    while (node)
    {
        node = node->next;
        n++;
    }
    return n;
}

Status Put(struct Queue **q, ElemType e)
{
    struct QueueNode *node = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    node->data = e;
    node->next = NULL;
    if ((*q)->rear == NULL)
        (*q)->rear = (*q)->front = node;
    else
    {
        (*q)->rear->next = node;
        (*q)->rear = node;
    }
    return OK;
}

Status Poll(struct Queue **q, ElemType *e)
{
    if ((*q)->front)
    {
        if ((*q)->rear == (*q)->front->next)
            (*q)->rear = NULL;
        *e = (*q)->front->data;
        (*q)->front = (*q)->front->next;
        return OK;
    }
    return ERROR;
}

Status Get(struct Queue *q, ElemType *e)
{
    if (q->front)
    {
        *e = q->front->data;
        return OK;
    }
    return ERROR;
}

int main()
{
    struct Queue *Q;
    int a = 10;
    printf("Empty?: %d \n", QueueEmpty(Q));
    InitQueue(&Q);
    printf("Empty?: %d \n", QueueEmpty(Q));
    printf("Length: %d\n", QueueLength(Q));
    Put(&Q, 12);
    Put(&Q, 12);
    Put(&Q, 12);
    Poll(&Q, &a);

    Put(&Q, 12);
    printf("Length: %d\n", QueueLength(Q));
    printf("Empty?: %d \n", QueueEmpty(Q));
    return 0;
}
