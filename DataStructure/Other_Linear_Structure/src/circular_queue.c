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
    return (q.rear - q.front + MAXSIZE) % MAXSIZE;
}

Status Put(struct Queue *q, ElemType e)
{
    if (((q->rear + 1) % MAXSIZE) != q->front)
    {
        q->data[q->rear] = e;
        q->rear = (q->rear + 1) % MAXSIZE;
        return OK;
    }
    return OVERFLOW;
}

Status Poll(struct Queue *q, ElemType *e)
{
    if (q->rear != q->front)
    {
        *e = q->data[q->front];
        q->front = (q->front + 1) % MAXSIZE;
        return OK;
    }
    return ERROR;
}

Status Get(struct Queue q, ElemType *e)
{
    if (q.front != q.rear)
    {
        *e = q.data[q.front];
        return OK;
    }
    return ERROR;
}

Status Show(struct Queue q)
{
    printf("SHOW\n");
    while (q.front != q.rear)
    {
        printf("%d ", q.data[q.front]);
        q.front = (q.front + 1) % MAXSIZE;
    }
    printf("\n");
    return OK;
}


int main()
{
    struct Queue Q;
    InitQueue(&Q);
    int a;
    /*
    for (int i = 0; i < 20; i++)
        Put(&Q, i * 10);
    printf("%d\n", QueueLength(Q));
    Poll(&Q, &a);
    printf("%d\n", QueueLength(Q));
    Get(Q, &a);
    printf("a: %d\n", a);
    printf("%d\n", QueueLength(Q));

    Show(Q);
    Poll(&Q, &a);
    Poll(&Q, &a);
    Show(Q);
    Put(&Q, 1);
    Put(&Q, 1);
    Show(Q);
    */
    for (int i = 0; i < 10; i++)
    {
        Put(&Q, i);
        printf("%d\n", QueueLength(Q));
    }

    printf("fuck: %d\n", QueueLength(Q));
    for (int i = 0; i < 10; i++)
    {
        Poll(&Q, &a);
        printf("%d\n", QueueLength(Q));
    }

    printf("fuck: %d\n", QueueLength(Q));
    for (int i = 0; i < 10; i++)
    {
        Put(&Q, i * 2);
        printf("%d\n", QueueLength(Q));
    }
    Show(Q);
    return 0;
}
