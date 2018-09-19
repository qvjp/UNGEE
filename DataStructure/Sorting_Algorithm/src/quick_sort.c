#include <stdio.h>
#include "sort.h"

void sort(struct D_SqList *l, int start, int end)
{
    if (start >= end)
        return;
    int mid = start;
    ElemType tmp = 0;
    for (int i = start, j = end; i < j;)
    {
        for (; l->elem[mid] <= l->elem[j] && j > i;)
        {
            j--;
        }
        tmp = l->elem[j];
        l->elem[j] = l->elem[mid];
        l->elem[mid] = tmp;
        mid = j;
        for (; l->elem[mid] >= l->elem[i] && i < j;)
        {
            i++;
        }
        tmp = l->elem[i];
        l->elem[i] = l->elem[mid];
        l->elem[mid] = tmp;
        mid = i;
    }
    sort(l, start, mid - 1);
    sort(l, mid + 1, end);
    // progress(l->length-(end-start),l->length);
}

void QuickSort(struct D_SqList *l)
{
    int len = l->length;
    sort(l, 0, len-1);
}
