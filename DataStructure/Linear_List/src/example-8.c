#include <stdio.h>
#include <stdlib.h>
#include "../../Common/src/types.h"

typedef struct {
    ElemType *elem;
    int length;
    int listsize;
}SqList;

typedef struct LNode {
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

void A1(SqList *L1, LinkList *L2)
{
    LinkList tmp = (*L2);
    for (int i = L1->length - 1; i >= 0; i--)
    {
        LNode *p = (LNode*)malloc(sizeof(LNode));
        p->data = L1->elem[i];
        tmp->next = p;
        tmp = p;
    }
}

int main()
{
    SqList* L1;
    L1 = malloc(sizeof(SqList));
    L1->elem = malloc(sizeof(ElemType) * 10);
    L1->length = 10;
    L1->listsize = 10;
    for (int i = 0; i < 10; i++)
        L1->elem[i] = i * 10;

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", L1->elem[i]);
    }
    printf("\n");


    LinkList L2;
    L2 = (LinkList)malloc(sizeof(struct LNode));
    L2->next = NULL;

    A1(L1, &L2);

    LinkList tmp = L2->next;
    for (int i =  0; i < 10; i++)
    {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}
