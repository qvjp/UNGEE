#include <stdio.h>
#include "sort.h"

/**
 * 获取枢纽元位置
 * 使用第一个或最后一个作为枢纽元会使已排序的序列排序缓慢
 * 这里使用中间位置,表现还可以
 */
int getPivot(struct D_SqList *l, int start, int end)
{
    return (start + end) / 2;
}

/**
 * flag 非0是由小到大
 */
void sort(struct D_SqList *l, int start, int end, int flag)
{
    if ((flag && (start > end)) || ((!flag) && (start > end)))
        return;
    int pivot = getPivot(l, start, end);
    int t; // 用于交换的临时变量
    ElemType tmp = l->elem[pivot]; // 保存枢纽元
    int i = start;
    int j = end;
    for (; i != j;)
    {
        for (; ((flag &&(tmp <= l->elem[j])) || (!flag && (tmp >= l->elem[j]))) && j > i;)
        {
            j--;
        }
        for (; ((flag && tmp >= l->elem[i]) || (!flag && tmp <= l->elem[i])) && i < j;)
        {
            i++;
        }
        if (j>i)
        {
            t = l->elem[i];
            l->elem[i] = l->elem[j];
            l->elem[j] = t;
        }
    }

    l->elem[start] = l->elem[j];
    l->elem[j] = tmp;

    sort(l, start, j - 1, flag);
    sort(l, j + 1, end, flag);
    // progress(l->length-(end-start),l->length);
}

void QuickSort(struct D_SqList *l, int flag)
{
    int len = l->length;
    sort(l, 0, len-1, flag);
}

