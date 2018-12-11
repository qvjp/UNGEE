#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void InsertionSort(struct D_SqList *l)
{
    int len = l->length;
    for (int i = 0; i < len; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (l->elem[j] <= l->elem[j-1])
            {
                swap(l, j, j-1);
            }
        }
#ifdef PROGRESS
        progress(i, len-2);
#endif
    }
}
