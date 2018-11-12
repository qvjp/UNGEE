#include "sequenticl_list.h"
#include <stdio.h>
#include <stdlib.h>

// 初始化顺序表
void InitList(struct D_SqList *L)
{
    L->elem = malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!L->elem)
        exit(OVERFLOW);
    L->length = 0;
    L->listsize = LIST_INIT_SIZE;
}

void InitSList(struct S_SqList *L)
{
    L->length = 0;
}

// 删除顺序表
void DestroyList(struct D_SqList *L)
{
    free(L->elem);
    L->elem = NULL;
    L->length = 0;
    L->listsize = 0;
}

// 清空顺序表
void ClearList(struct D_SqList *L)
{
    L->length = 0;
}

// 判断顺序表是否为空，若为空返回TRUE，否则FALSE
Status ListEmpty(struct D_SqList L)
{
    if (L.length == 0)
        return TRUE;
    return FALSE;
}

// 返回顺序表长度
int ListLength(struct D_SqList L)
{
    return L.length;
}

// 获取第i个值，置于e
Status GetElem(struct D_SqList L, int i, ElemType *e)
{
    if (i < 1 || i > L.length)
        return ERROR;
    *e = L.elem[i - 1];
    return OK;
}

// 返回e的位置
int LocateElem(struct D_SqList L, ElemType e)
{
    int i = 0;
    for(; i < L.length; i++)
    {
        if (L.elem[i] == e)
            break;
    }
    if (i >= L.length)
        return 0;
    else
        return i + 1;
}

// 返回cur_e的前驱给pre_e
Status PriorElem(struct D_SqList L, ElemType cur_e, ElemType *pre_e)
{
    int i = 1;
    for (; i < L.length; i++)
    {
        if(L.elem[i] == cur_e)
        {
            *pre_e = L.elem[i - 1];
            break;
        }
    }
    if (i < L.length)
        return OK;
    else
        return INFEASIBLE;
}

// 返回cur_e的后继给next_e
Status NextElem(struct D_SqList L, ElemType cur_e, ElemType *next_e)
{
    int i = 0;
    for (; i < L.length - 1; i++)
    {
        if (L.elem[i] == cur_e)
        {
            *next_e = L.elem[i + 1];
            break;
        }
    }
    if (i < L.length - 1)
        return OK;
    else
        return INFEASIBLE;
}

// 在线性表第i个位置插入e, i从1开始
Status ListInsert(struct D_SqList *L, int i, ElemType e)
{
    if (i < 1 || i > L->length + 1)
        return ERROR;
    if (L->length >= L->listsize)
    {
        ElemType *newBase;
        newBase = realloc(L->elem, (L->listsize + LIST_INCREMENT) * sizeof(ElemType));
        if (!newBase)
            exit(OVERFLOW);
        L->elem = newBase;
        L->listsize += LIST_INCREMENT;
    }
    ElemType *p, *q;
    q = &(L->elem[i - 1]);
    for (p = &(L->elem[L->length - 1]); p >= q; --p)
        p[1] = *p;
    *q = e;
    L->length++;
    return OK;
}

Status SListInsert(struct S_SqList *L, int i, ElemType e)
{
    if (i < 1 || i > L->length + 1)
        return ERROR;
    if (L->length >= LIST_MAX_SIZE)
        return OVERFLOW;
    for (int j = i - 1; j < L->length; j++)
    {
        L->elem[j + 1] = L->elem[j];
    }
    L->elem[i - 1] = e;
    L->length++;
    return OK;
}

// 删除线性表第i个位置元素，并赋值给e
Status ListDelete(struct D_SqList *L, int i, ElemType *e)
{
    if (i < 1 || i > L->length)
    {
        return ERROR;
    }
    *e = L->elem[i - 1];
    for (int j = i; j < L->length; j++)
    {
        L->elem[j - 1] = L->elem[j];
    }
    L->length--;
    return OK;
}

Status ListShow(struct D_SqList L)
{
    for (int i = 0; i < L.length; i++)
    {
        printf("%d ", L.elem[i]);
    }
    printf("\n");
    return OK;
}


void PlayDList()
{
    struct D_SqList L;
    printf("%d, %d\n", ListLength(L), L.listsize);
    InitList(&L);
    printf("%d, %d\n", ListLength(L), L.listsize);
    for (int i = 1; i <= 13; i++)
    {
        ListInsert(&L, i, i * 10);
    }
    printf("%d, %d\n", ListLength(L), L.listsize);
    int a = 0;
    printf("before-GetElem: a = %d\n", a);
    GetElem(L, 2, &a);
    printf("after-GetElem: a = %d\n", a);
    printf("%d\n", LocateElem(L, 20));
    ListShow(L);
    ListDelete(&L, 1, &a);
    printf("after-ListDelete: a = %d\n", a);
    ListShow(L);
    ElemType b;
    printf("NextElem Status: %d\n", NextElem(L, 10, &b));
    printf("after-NextElem: b = %d\n", b);
    ListInsert(&L, 1, 10);
    printf("NextElem Status: %d\n", NextElem(L, 10, &b));
    printf("after-NextElem: b = %d\n", b);
    ListShow(L);
    printf("PriorElem Status: %d\n", PriorElem(L, 110, &b));
    printf("after-PriorElem: b = %d\n", b);
    printf("DestroyList:\n");
    DestroyList(&L);
    ListShow(L);
}

void PlaySList()
{
    struct S_SqList L;
    printf("%d\n", L.length);
    InitSList(&L);
    printf("%d\n", L.length);
    for (int i = 1; i <= 13; i++)
    {
        SListInsert(&L, i, i * 10);
    }
    printf("%d\n", L.length);
}

/*
int main()
{
    PlayDList();
    PlaySList();
    return 0;
}
*/
