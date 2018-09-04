#ifndef __SEQUENTIAL_STACK_H
#define __SEQUENTIAL_STACK_H

#include "../../Common/src/types.h"

struct StackNode
{
    ElemType data;
    struct StackNode *next;
};

// 初始化一个空栈
Status InitStack(struct StackNode **s);
// 判断栈是否为空栈
Status StackEmpty(struct StackNode *s);
// 在栈顶放入元素
Status Push(struct StackNode **s, ElemType e);
// 在栈顶取出元素
Status Pop(struct StackNode **s, ElemType *e);
// 获取栈顶元素的值
Status GetTopElem(struct StackNode *s, ElemType *e);

#endif /* __SEQUENTIAL_STACK_H */
