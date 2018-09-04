#include "linked_stack.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * 这里我使用的是不带头节点的栈
 */

// 初始化一个空栈
Status InitStack(struct StackNode **s)
{
   (*s) = NULL; 
   return OK;
}

// 判断栈是否为空栈,空返回TRUE(0)
Status StackEmpty(struct StackNode *s)
{
    if (s)
    {
        return FALSE;
    }
    return TRUE;
}

// 在栈顶放入元素
Status Push(struct StackNode **s, ElemType e)
{
    struct StackNode *node = (struct StackNode*)malloc(sizeof(struct StackNode));
    if (!node)
    {
        return ERROR;
    }
    node->data = e;
    node->next = (*s);
    (*s) = node;
    return OK;
}

// 在栈顶取出元素
Status Pop(struct StackNode **s, ElemType *e)
{
    if (!*s)
        return ERROR;
    *e = (*s)->data;
    (*s) = (*s)->next;
    return OK;
}

// 获取栈顶元素的值
Status GetTopElem(struct StackNode *s, ElemType *e)
{
    if (s)
    {
        *e = s->data;
        return OK;
    }
    return ERROR;
}

/*
int main()
{
    struct StackNode *S;
    printf("%d\n", StackEmpty(S));
    InitStack(&S);
    printf("after-InitStack: %d\n", StackEmpty(S));

    Push(&S, 12);
    printf("after-Push: %d\n", StackEmpty(S));

    ElemType a;
    Pop(&S, &a);
    printf("after-Pop: %d\n", StackEmpty(S));

    Push(&S, 219);
    Push(&S, 223);

    Pop(&S, &a);
    GetTopElem(S, &a);
    printf("GetTopElem: %d\n", a);
}
*/
