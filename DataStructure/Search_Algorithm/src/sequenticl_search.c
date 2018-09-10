#include <stdio.h>
#include <stdlib.h>
#include "sequenticl_search.h"

// 不设置哨兵的顺序查找
int SeqSearch1(struct D_SqList l, ElemType key)
{
    for(int i = 1; i <= l.length; i++)
    {
        if (l.elem[i] == key)
        {
            return i;
        }
    }
    return -1;
}

// 设置哨兵的顺序查找
int SeqSearch2(struct D_SqList l, ElemType key)
{
    int i = 0;
    // 下边一行由于是for内部为空，gcc默认会warning，我就把它注释了
    // for (i = l.length; l.elem[i] != key; i--);
        return i;
}

// 对已排序序列顺序查找
// flag为0是升序，否则降序
int SeqedSearch(struct D_SqList l, int flag, ElemType key)
{
    for (int i = 0; i < l.length; i++)
    {
        if (l.elem[i] == key)
            return i;
        if (flag && (l.elem[i] < key))
        {
            return -1;
        }
        else if (!flag && (l.elem[i] > key))
        {
            return -1;
        }
    }
    return -1;
}

// flag为0是升序，否则降序
int BinarySearch(struct D_SqList l, int flag, ElemType key)
{
    int low = 0;
    int high = l.length;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (key == l.elem[mid])
        {
            return mid;
        }
        else if (!flag && (key > l.elem[mid]))
            low = mid + 1;
        else if (!flag && (key < l.elem[mid]))
            high = mid - 1;
        else if (flag && (key > l.elem[mid]))
            high = mid - 1;
        else if (flag && (key < l.elem[mid]))
            low = mid + 1;
    }
    return -1;
}

// b为已分好的块
// index为索引数组
// p q分别时结果所在的块下标和在块内的下标
Status BlockSearch(struct Block *b, int *index, ElemType key, int *p, int *q)
{
    int i = 0;
    int j = 0;
    for (i = 0; ;i++)
    {
        if (index[i] >= key)
            break;
    }
    for (j = 0; j < b[i].length; j++)
    {
        if (b[i].elem[j] == key)
            break;
    }
    *p = i;
    *q = j;
    return 0;
}

int main()
{
    struct Block b[4] = {{{2,43,26,25,15},5},{{52,44,59,67,60},5},{{68,70,72,69,76},5},{{81,74,68,87,96},5}};
    int index[4] = {43,67,76,96};
    int i = 0;
    int j = 0;
    BlockSearch(b,index,69,&i, &j);

    printf("%d %d\n", i, j);


/*
    struct D_SqList L;
    int a = 0;
    InitList(&L);
    for (int i = 1; i < 21; i++)
        ListInsert(&L, i, i);
    //a = SeqSearch1(L, 914);
    // a = SeqedSearch(L, 0, 4);
    for (int i = 0; i < 22; i++)
    {
        a = BinarySearch(L, 0, i);
        printf("%d: %d\n", i, a);
    }
    // ListInsert(&L, 1, 914);
    // a = SeqSearch2(L, 914);
    return 0;
    */
}
