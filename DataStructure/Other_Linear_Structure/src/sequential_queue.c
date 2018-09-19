#include "sequential_queue.h"
#include <stdio.h>
#include <stdlib.h>

/*
struct Queue
{
    ElemType data[MAXSIZE];
    int front;
    int rear;
};
*/

Status InitQueue(struct Queue *q)
{
    q->front = 0;
    q->rear = 0;
    return OK;
}

Status InitDQueue(struct D_Queue *q)
{
    q->data = malloc(sizeof(ElemType) * QUEUE_INIT_SIZE);
    if (!q->data)
    {
        return ERROR;
    }
    q->front = 0;
    q->rear = 0;
    q->queue_size = QUEUE_INIT_SIZE;
    return OK;
}

void ShowQueue(struct Queue q)
{
    struct Queue p = q;
    ElemType a = 0;
    int len  = QueueLength(p);
    for (int i = 0; i < len; i++)
    {
        Poll(&p, &a);
        printf("%d ", a);
    }
    printf("\n");
}

void ShowDQueue(struct D_Queue q)
{
    struct D_Queue p = q;
    ElemType a = 0;
    int len  = DQueueLength(p);
    for (int i = 0; i < len; i++)
    {
        DPoll(&p, &a);
        printf("%d ", a);
    }
    printf("\n");
}

Status QueueEmpty(struct Queue q)
{
    if (!(q.rear && q.front))
    {
        return TRUE;
    }
    return FALSE;
}
Status DQueueEmpty(struct D_Queue q)
{
    if (!(q.rear && q.front))
    {
        return TRUE;
    }
    return FALSE;
}

int QueueLength(struct Queue q)
{
    return q.rear - q.front;
}
int DQueueLength(struct D_Queue q)
{
    return q.rear - q.front;
}

Status Put(struct Queue *q, ElemType e)
{
    if (q->rear < MAXSIZE)
    {
        q->data[q->rear] = e;
        q->rear++;
        return OK;
    }
    return OVERFLOW;
}
Status DPut(struct D_Queue *q, ElemType e)
{
    if (q->rear > q->queue_size - 1)
    {
        ElemType *newBase;
        newBase = realloc(q->data, sizeof(ElemType) * (QUEUE_INCREMENT + q->queue_size));
        if (!newBase)
        {
            exit(ERROR);
        }
        q->data = newBase;
        q->queue_size += QUEUE_INCREMENT;
    }
    q->data[q->rear] = e;
    q->rear++;
    return OK;
    return OVERFLOW;
}

Status Poll(struct Queue *q, ElemType *e)
{
    if (q->front < q->rear)
    {
        *e = q->data[q->front];
        q->front++;
        return OK;
    }
    return ERROR;
}
Status DPoll(struct D_Queue *q, ElemType *e)
{
    if (q->front < q->rear)
    {
        *e = q->data[q->front];
        q->front++;
        return OK;
    }
    return ERROR;
}

Status Get(struct Queue q, ElemType *e)
{
    if (q.front < q.rear)
    {
        *e = q.data[q.front];
        return OK;
    }
    return ERROR;
}
Status DGet(struct D_Queue q, ElemType *e)
{
    if (q.front < q.rear)
    {
        *e = q.data[q.front];
        return OK;
    }
    return ERROR;
}

/*

int main()
{
    struct Queue Q;
    struct D_Queue DQ;
    InitDQueue(&DQ);
    InitQueue(&Q);
    int a;
    printf("Q:%d\n", QueueLength(Q));
    printf("DQ:%d\n", DQueueLength(DQ));
    Put(&Q, 11);
    DPut(&DQ, 11);
    printf("Q:%d\n", QueueLength(Q));
    printf("DQ:%d\n", DQueueLength(DQ));
    
    Poll(&Q, &a);
    DPoll(&DQ, &a);
    printf("Q:%d\n", QueueLength(Q));
    printf("DQ:%d\n", DQueueLength(DQ));
    Put(&Q, 12);
    DPut(&DQ, 12);
    Get(Q, &a);
    DGet(DQ, &a);
    printf("%d\n", a);
    printf("%d\n", QueueLength(Q));
    printf("%d\n", DQueueLength(DQ));


    printf("**************\n");
    for (int i = 0; i < 100; i++)
    {
        Put(&Q, i);
        DPut(&DQ, i);
    }
    ShowQueue(Q);
    ShowQueue(Q);
    ShowDQueue(DQ);
    ShowDQueue(DQ);
    return 0;
}
*/
