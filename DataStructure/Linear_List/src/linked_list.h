#ifndef __LINKED_LIST_H
#define __LINKED_LIST_H

#include "../../Common/src/types.h"

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
struct DNode
{
    ElemType data;
    struct DNode *Prior;
    struct DNode *next;
};

typedef struct LNode* LinkList;

//初始化一个单链表，具有头指针，头结点，头结点->next=NULL
int InitList(LinkList *L);
//头插法创建一个链表，链表长度为n
int CreateListHead(LinkList *L, int n);
//尾插法创建一个链表，链表长度为n
int CreateListTail(LinkList *L, int n);
//获取单链表的长度
int Getlength(LinkList L);
//获取链表中第i个位置处节点的数据元素
int GetElem(LinkList L,int i,ElemType *e);
//在链表的指定位置（i节点）插入一个节点
int InsertList(LinkList *L, int i, ElemType data);
//给链表追加一个节点，在最末尾处增加
int InsertListTail(LinkList *L, ElemType data);
//删除指定位置（i节点）处的节点
int DeleteList(LinkList *L, int i, ElemType *data);
// 清空整个链表
int ClearList(LinkList *L);
//打印整个链表；
int ShowList(LinkList L);

#endif /* __LINKED_LIST_H */
