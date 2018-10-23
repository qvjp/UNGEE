#include <stdio.h>
#include "sort.h"
#define PROGRESS

void adjustHeap(struct D_SqList *l, int parent, int length)
{
    int tmp = l->elem[parent];
    int child = 2 * parent + 1; // 左孩子
    while (child < length)
    {
        // 如果右孩子存在
        if (child + 1 < length && l->elem[child] < l->elem[child + 1])
            child++;
        if (tmp >= l->elem[child])
            break;
        l->elem[parent] = l->elem[child];
        parent = child;
        child = 2 * parent + 1;
    }
    l->elem[parent] = tmp;
}

void HeapSort(struct D_SqList *l)
{
    int len = l->length;
    for (int i = len / 2 - 1; i >= 0; i--)
    {
        adjustHeap(l, i, len);
    }
    for (int i = len - 1; i > 0; i--)
    {
#ifdef PROGRESS
        progress(len-i, len-1);
#endif
        int tmp = l->elem[i];
        l->elem[i] = l->elem[0];
        l->elem[0] = tmp;
        adjustHeap(l, 0, i);
    }
}

