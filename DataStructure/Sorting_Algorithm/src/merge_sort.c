#include <stdio.h>
#include "sort.h"

void merge(struct D_SqList *l, int reg[], int start, int end)
{
    if (start >= end)
        return;
    int len = end -start;
    int mid = len / 2 + start;
    int start1 = start;
    int end1 = mid;
    int start2 = mid + 1;
    int end2 = end;
    merge(l, reg, start1, end1);
    merge(l, reg, start2, end2);
    int k = start;
    while (start1 <= end1 && start2 <= end2)
        reg[k++] = l->elem[start1] < l->elem[start2] ? l->elem[start1++] : l->elem[start2++];
    while (start1 <= end1)
        reg[k++] = l->elem[start1++];
    while (start2 <= end2)
        reg[k++] = l->elem[start2++];
    for (k = start; k <= end; k++)
        l->elem[k] = reg[k];
}

void MergeSort(struct D_SqList *l)
{
    int len = l->length;
    int reg[len];
    merge(l, reg, 0, len-1);
}
