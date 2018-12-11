#include <stdio.h>
#include "sort.h"

void merge(struct D_SqList *l, int start1, int end1, int start2, int end2, int reg[])
{
    int k = start1;
    int top = k;
    while (start1 <= end1 && start2 <= end2)
        reg[k++] = l->elem[start1] < l->elem[start2] ? l->elem[start1++] : l->elem[start2++];
    while (start1 <= end1)
        reg[k++] = l->elem[start1++];
    while (start2 <= end2)
        reg[k++] = l->elem[start2++];
    for (k = top; k <= end2; k++)
        l->elem[k] = reg[k];
}


// 递归版
void mSort(struct D_SqList *l, int reg[], int start, int end)
{
    if (start >= end)
        return;
    int len = end - start;
    int mid = len / 2 + start;
    int start1 = start;
    int end1 = mid;
    int start2 = mid + 1;
    int end2 = end;
    mSort(l, reg, start1, end1);
    mSort(l, reg, start2, end2);
    merge(l, start1, end1, start2, end2, reg); 
}


void MergeSort(struct D_SqList *l)
{
    int len = l->length;
    int reg[len];
    mSort(l, reg, 0, len-1);
}
