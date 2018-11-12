#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

//初始化一个单链表，具有头指针，头结点，头结点->next=NULL
Status InitList(LinkList *L)
{
    (*L) = (LinkList)malloc(sizeof(struct LNode));
    (*L)->next = NULL;
    return OK;
}

//头插法创建一个链表，链表长度为n
Status CreateListHead(LinkList *L, int n)
{
    struct LNode *p;
    for (int i = 0; i < n; i++)
    {
        p = (struct LNode*)malloc(sizeof(struct LNode));
        p->data = i;
        p->next = (*L)->next;
        (*L)->next = p;
    }
    return OK;
}
// 尾插法创建一个链表，链表长度为n
Status CreateListTail(LinkList *L, int n)
{
    struct LNode *p, *tmp;
    tmp = (*L);
    for (int i = 0; i < n; i++)
    {
        p = (struct LNode*)malloc(sizeof(struct LNode));
        p->data = i;
        p->next = NULL;
        tmp->next = p;
        tmp = p;
    }
    return OK;
}
//获取单链表的长度
int Getlength(LinkList L)
{
    int i = 0;
    for(;;i++)
    {
        if(L->next)
            L=L->next;
        else
            break;
    }
    return i;
}
//获取链表中第i个位置处节点的数据元素
Status GetElem(LinkList L,int i,ElemType *e)
{
    if (i < 1)
        return ERROR;
    LinkList tmp = L;
    for (int j = 0; j < i; j++)
    {
        tmp = tmp->next;
    }
    *e = tmp->data;
    return OK;
}
// 在链表的指定位置（第i个节点）插入一个节点
Status InsertList(LinkList *L, int i, ElemType data)
{
    if (i < 1)
        return ERROR;
    LinkList tmp;
    struct LNode *node = (struct LNode*)malloc(sizeof(struct LNode));
    node->data = data;
    tmp = (*L);
    for (int j = 0; j < i; j++)
    {
        if (tmp->next)
            tmp = tmp->next;
    }
    if (!(tmp->next))
        return ERROR;
    node->next = tmp->next;
    tmp->next = node;
    return OK;
}

// 在双链表中第i个位置之前插入一个节点
Status InsertDoublyList(DoublyLinkList *L, int i, ElemType data)
{
    DoublyLinkList p, s;
    if (i < 1)
        return ERROR;
    p = (*L);
    for (int j = 1; j <= i; j++)
    {
        p = p->next;
    }
    if (!p)
        return ERROR;
    s = (DoublyLinkList)malloc(sizeof(struct DoublyLNode));
    if (!s)
        return OVERFLOW;
    s->data = data;
    s->prior = p; // 在第i-1个元素之后插入
    s->next = p->next;
    p->next->prior = s;
    p->next = s;
    return OK;
}

//给链表追加一个节点，在最末尾处增加
Status InsertListTail(LinkList *L, ElemType data)
{
    LinkList tmp;
    struct LNode *node = (struct LNode*)malloc(sizeof(struct LNode));
    node->data = data;
    tmp = (*L);
    for (;;)
    {
        if (tmp->next)
            tmp = tmp->next;
        else
        {
            tmp->next = node;
            break;
        }
    }
    return OK;
}
//删除指定位置（第i个节点）处的节点
Status DeleteList(LinkList *L, int i, ElemType *data)
{
    if (i < 1)
        return ERROR;
    LinkList tmp;
    struct LNode *node;
    tmp = (*L);
    for (int j = 0; j < i - 1; j++)
    {
        if (tmp->next)
            tmp = tmp->next;
        else
            return ERROR;
    }
    *data = tmp->next->data;
    node = tmp->next->next;
    free(tmp->next);
    tmp->next = node;
    return OK;
}

Status DeleteDoublyList(DoublyLinkList *L, int i, ElemType *e) {
    DoublyLinkList p;
    if (i < 1)
        return ERROR;
    p = (*L);
    for (int j = 1; j <= i; j++)
    {
        p = p->next;
    }
    if (!p)
        return ERROR;
    *e = p->data;
    p->prior->next = p->next;
    p->next->prior = p->prior;
    free(p);
    return OK;
}

// 清空整个链表
Status ClearList(LinkList *L)
{
    LinkList tmp;
    struct LNode *p;
    tmp = (*L)->next;
    for (;;)
    {
        if (tmp->next)
        {
            p = tmp->next;
            free(tmp);
            tmp = p;
        }
        else
            break;
    }
    (*L)->next = NULL;
    return OK;
}
//打印整个链表；
Status ShowList(LinkList L)
{
    LinkList p;
    int i = 0;
    p = L->next;
    while (p) {
        i++;
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
    return OK;
}

int main()
{
    LinkList L;
    InitList(&L);
    ShowList(L);
    CreateListHead(&L, 33);
    // CreateListTail(&L, 33);
    ShowList(L);
    printf("%d\n", Getlength(L));
    ElemType a = 0;
    GetElem(L, 0, &a);
    printf("%d\n", a);
    InsertList(&L, 22, 100);
    printf("after-InsertList: %d\n", Getlength(L));
    ShowList(L);
    InsertListTail(&L, 200);
    printf("after-InsertListTail: %d\n", Getlength(L));
    ShowList(L);
    DeleteList(&L, 35, &a);
    printf("Delete Element: %d\n", a);
    printf("after-DeleteList-length: %d\n", Getlength(L));
    ShowList(L);
    ClearList(&L);
    printf("after-ClearList: %d\n", Getlength(L));
    return 0;
}

