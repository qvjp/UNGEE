#include "sequential_queue.h"
#include <stdio.h>

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

Status QueueEmpty(struct Queue q)
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

Status Get(struct Queue q, ElemType *e)
{
    if (q.front < q.rear)
    {
        *e = q.data[q.front];
        return OK;
    }
    return ERROR;
}


int main()
{
    struct Queue Q;
    InitQueue(&Q);
    int a;
    printf("%d\n", QueueLength(Q));
    Put(&Q, 11);
    printf("%d\n", QueueLength(Q));
    Put(&Q, 17);
    Put(&Q, 13);
    Put(&Q, 13);
    Poll(&Q, &a);
    Poll(&Q, &a);
    Poll(&Q, &a);
    Put(&Q, 13);
    Put(&Q, 13);
    Put(&Q, 13);
    Put(&Q, 13);
    Put(&Q, 13);
    Put(&Q, 13);
    Put(&Q, 13);
    Put(&Q, 13);
    Put(&Q, 13);
    Put(&Q, 13);
    Put(&Q, 13);
    Put(&Q, 13);
    Put(&Q, 13);
    Put(&Q, 13);
    Put(&Q, 13);
    Put(&Q, 13);
    Put(&Q, 13);
    Put(&Q, 13);
    Put(&Q, 13);
    Put(&Q, 13);
    Put(&Q, 13);
    Put(&Q, 14);
    printf("%d\n", QueueLength(Q));
    Poll(&Q, &a);
    printf("%d\n", QueueLength(Q));
    Get(Q, &a);
    printf("%d\n", a);
    printf("%d\n", QueueLength(Q));
    return 0;
}
