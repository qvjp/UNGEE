#ifndef __LINKED_LIST_H
#define __LINKED_LIST_H

#include "../../Common/src/types.h"

#define MAXSIZE 10

/**
 * 单链表节点类型
 */
struct LNode
{
    ElemType data;
    struct LNode *next;
};

/**
 * 静态链表类型
 */
struct SLNode
{
    ElemType data;
    int next;
};

/**
 * 双链表节点类型
 */
struct DoublyLNode
{
    ElemType data;
    struct DoublyLNode *prior;
    struct DoublyLNode *next;
};

typedef struct LNode* LinkList;
typedef struct SLNode SLinkList[MAXSIZE];
typedef struct DoublyLNode* DoublyLinkList;

// 初始化一个单链表，具有头指针，头结点，头结点->next=NULL
Status InitList(LinkList *L);
// 头插法创建一个链表，链表长度为n
Status CreateListHead(LinkList *L, int n);
// 尾插法创建一个链表，链表长度为n
Status CreateListTail(LinkList *L, int n);
// 获取单链表的长度
int Getlength(LinkList L);
// 获取链表中第i个位置处节点的数据元素
Status GetElem(LinkList L,int i,ElemType *e);
// 在链表的指定位置（i节点）插入一个节点
Status InsertList(LinkList *L, int i, ElemType data);
// 在双链表中第i个位置之前插入一个节点
Status InsertDoublyList(DoublyLinkList *L, int i, ElemType data);
// 给链表追加一个节点，在最末尾处增加
Status InsertListTail(LinkList *L, ElemType data);
// 删除指定位置（i节点）处的节点
Status DeleteList(LinkList *L, int i, ElemType *data);
// 删除双向链表第i个节点
Status DeleteDoublyList(DoublyLinkList *L, int i, ElemType *e);
// 清空整个链表
Status ClearList(LinkList *L);
// 打印整个链表；
Status ShowList(LinkList L);

#endif /* __LINKED_LIST_H */
