#include <stdio.h>
#include "sort.h"

void SelectionSort(struct D_SqList *l)
{
    int len = l->length;
    int min = 0;
    for (int i = 0; i < len - 1; i++)
    {
        min = i;
        for (int j = i; j < len; j++)
        {
            if (l->elem[min] > l->elem[j])
            {
                min = j;
            }
        }
        swap(l, i, min);
#ifdef PROGRESS
        progress(i, len-2);
#endif
    }
}

