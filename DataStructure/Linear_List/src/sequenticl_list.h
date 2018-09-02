#ifndef __SEQUENTIAL_LIST_H
#define __SEQUENTIAL_LIST_H

#include "../../Common/src/types.h"

#define LIST_MAX_SIZE 20

#define LIST_INIT_SIZE 10
#define LIST_INCREMENT 5

/*
* 顺序表的固定内存分配结构
*/
struct S_SqList
{
    ElemType elem[LIST_MAX_SIZE];
    int length;
};

/*
* 顺序表的动态内存分配结构
*/
struct D_SqList
{
    ElemType *elem;
    int length;
    int listsize;
};


// 初始化顺序表
void InitList(struct D_SqList *L);
void InitSList(struct S_SqList *L);
// 删除顺序表
void DestroyList(struct D_SqList *L);
// 清空顺序表
void ClearList(struct D_SqList *L);
// 判断顺序表是否为空，若为空返回TRUE，否则FALSE
Status ListEmpty(struct D_SqList L);
// 返回顺序表长度
int ListLength(struct D_SqList L);
// 获取第i个值，置于e
Status GetElem(struct D_SqList L, int i, ElemType *e);
// 返回e的位置
int LocateElem(struct D_SqList L, ElemType e);
// 返回cur_e的前驱给pre_e
Status PriorElem(struct D_SqList L, ElemType cur_e, ElemType *pre_e);
// 返回cur_e的后继给next_e
Status NextElem(struct D_SqList L, ElemType cur_e, ElemType *next_e);
// 在线性表第i个位置插入e
Status ListInsert(struct D_SqList *L, int i, ElemType e);
Status SListInsert(struct S_SqList *L, int i, ElemType e);
// 删除线性表第i个位置元素，并赋值给e
Status ListDelete(struct D_SqList *L, int i, ElemType *e);
// 打印顺序表的内容
Status ListShow(struct D_SqList L);


#endif /* __SEQUENTIAL_LIST_H */
