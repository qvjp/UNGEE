#include <stdio.h>
#include "sort.h"
#define PROGRESS

void BubbleSort(struct D_SqList *l)
{
    int len = l->length;
    int tmp = 0;
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            if (l->elem[j] > l->elem[j + 1])
            {
                tmp = l->elem[j];
                l->elem[j] = l->elem[j + 1];
                l->elem[j + 1] = tmp;
            }
        }
#ifdef PROGRESS
        progress(i, len-2);
#endif
    }
}

