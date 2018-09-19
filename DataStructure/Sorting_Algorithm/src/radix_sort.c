#include <stdio.h>
#include "sort.h"
#include "../../Other_Linear_Structure/src/sequential_queue.h"

int getMax(struct D_SqList l)
{
    int i, max;

    int len = l.length;
    max = l.elem[0];
    for (i = 1; i < len; i++)
        if (l.elem[i] > max)
            max = l.elem[i];
    return max;
}

void RadixSort(struct D_SqList *l)
{
    int max = getMax(*l);
    int len = l->length;
    struct D_Queue Q[10];
    //struct Queue Q[10];
    int time = 1;
    for (int i = 0; i < 10; i++)
    {
        InitDQueue(&Q[i]);
    }

    while (max / time)
    {
        int d = 0;
        // 提取一位，放到对应的桶中
        for (int i = 0; i < len; i++)
        {
            d = (l->elem[i] % (time * 10) / time);
            DPut(&Q[d], l->elem[i]);
        }
        // 依次将桶中的数据取出，放回序列
        ClearList(l);
        for (int k = 0, i = 0; k < 10; k++)
        {
            int a = 0;
            while (DQueueLength(Q[k]))
            {
                DPoll(&Q[k], &a);
                ListInsert(l, i + 1, a);
                i++;
            }
        }
        time *= 10;
    }
}

