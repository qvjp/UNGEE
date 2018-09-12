#ifndef __SEQUENTIAL_STACK_H
#define __SEQUENTIAL_STACK_H

#include "../../Common/src/types.h"

#define MAXSIZE 100000
struct Queue
{
    ElemType data[MAXSIZE];
    int front;
    int rear;
};

// 初始化队列
Status InitQueue(struct Queue *q);
// 判断队列是否为空
Status QueueEmpty(struct Queue q);
// 返回队列长度
int QueueLength(struct Queue q);
// 在队尾放入元素
Status Put(struct Queue *q, ElemType e);
// 在队首取出元素
Status Poll(struct Queue *q, ElemType *e);
// 获取队首元素值
Status Get(struct Queue q, ElemType *e);

void ShowQueue(struct Queue q);

#endif /* __SEQUENTIAL_STACK_H */
