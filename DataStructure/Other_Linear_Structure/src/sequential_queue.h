#ifndef __SEQUENTIAL_STACK_H
#define __SEQUENTIAL_STACK_H

#include "../../Common/src/types.h"

#define MAXSIZE 100000

#define QUEUE_INIT_SIZE 500
#define QUEUE_INCREMENT 500

// 固定大小的顺序队列
struct Queue
{
    ElemType data[MAXSIZE];
    int front;
    int rear;
};

// 动态分配大小的顺序存储队列
struct D_Queue
{
    ElemType *data;
    int front;
    int rear;
    int queue_size;
};

// 初始化队列
Status InitQueue(struct Queue *q);
Status InitDQueue(struct D_Queue *q);
// 判断队列是否为空
Status QueueEmpty(struct Queue q);
Status DQueueEmpty(struct D_Queue q);
// 返回队列长度
int QueueLength(struct Queue q);
int DQueueLength(struct D_Queue q);
// 在队尾放入元素
Status Put(struct Queue *q, ElemType e);
Status DPut(struct D_Queue *q, ElemType e);
// 在队首取出元素
Status Poll(struct Queue *q, ElemType *e);
Status DPoll(struct D_Queue *q, ElemType *e);
// 获取队首元素值
Status Get(struct Queue q, ElemType *e);
Status DGet(struct D_Queue q, ElemType *e);

void ShowQueue(struct Queue q);
void DShowQueue(struct D_Queue q);

#endif /* __SEQUENTIAL_STACK_H */
