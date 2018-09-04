#ifndef __SEQUENTIAL_STACK_H
#define __SEQUENTIAL_STACK_H

#include "../../Common/src/types.h"

#define MAXSIZE 10

/**
 * 栈的顺序存储类型
 */
struct Stack
{
    ElemType data[MAXSIZE];
    int top;
};


// 初始化一个空栈
Status InitStack(struct Stack *s);
// 判断栈是否为空栈
Status StackEmpty(struct Stack s);
// 在栈顶放入元素
Status Push(struct Stack *s, ElemType e);
// 在栈顶取出元素
Status Pop(struct Stack *s, ElemType *e);
// 获取栈顶元素的值
Status GetTopElem(struct Stack s, ElemType *e);

#endif /* __SEQUENTIAL_STACK_H */
