#include <stdio.h>
#include "sort.h"


/**
 * 构建大顶堆
 */
void adjustHeap(struct D_SqList *l, int parent, int length)
{
    int child = 2 * parent + 1; // 左孩子
    while (child < length) // 若存在左孩子
    {
        // child为较小的孩子
        if (child + 1 < length && l->elem[child] < l->elem[child + 1])
            child++;
        if (l->elem[parent] >= l->elem[child])
            break;
        swap(l, parent, child);
        parent = child;
        child = 2 * child + 1;
    }
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
// 是否显示进度条
#ifdef PROGRESS
        progress(len-i, len-1);
#endif
        swap(l, i, 0);
        adjustHeap(l, 0, i);
    }
}

