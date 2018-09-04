#include "sequential_stack.h"
#include <stdio.h>

Status InitStack(struct Stack *s)
{
    s->top = -1;
    return OK;
}

Status StackEmpty(struct Stack s)
{
    if (s.top == -1)
        return TRUE;
    else
        return FALSE;
}

Status Push(struct Stack *s, ElemType e)
{
    if (s->top < MAXSIZE - 1)
    {
        s->top++;
        s->data[s->top] = e;
        return OK;
    }
    else
        return OVERFLOW;
}

Status Pop(struct Stack *s, ElemType *e)
{
    if (s->top == -1)
        return ERROR;
    else
    {
        *e = s->data[s->top--];
    }
    return OK;
}

Status GetTopElem(struct Stack s, ElemType *e)
{
    if (s.top == -1)
        return ERROR;
    else
    {
        *e = s.data[s.top];
    }
    return OK;
}

int main()
{
    struct Stack S;
    printf("%d\n", StackEmpty(S));
    InitStack(&S);
    printf("%d\n", StackEmpty(S));

    Push(&S, 12);
    printf("%d\n", StackEmpty(S));

    ElemType a;
    Pop(&S, &a);
    printf("%d\n", StackEmpty(S));

    Push(&S, 21);
    Push(&S, 22);

    GetTopElem(S, &a);
    printf("%d\n", a);
}
