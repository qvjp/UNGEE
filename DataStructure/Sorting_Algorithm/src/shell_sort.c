#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void ShellSort(struct D_SqList *l)
{
    int len = l->length;
    ElemType tmp = 0;
    for (int step = len / 2; step >= 1; step /= 2)
    {
        for (int i = 0; i < len; i+=step)
        {
            for (int j = i; j > 0; j -= step)
            {
                if (l->elem[j] < l->elem[j - step])
                {
                    tmp = l->elem[j];
                    l->elem[j] = l->elem[j-step];
                    l->elem[j-step] = tmp;
                }
            }
        }
#ifdef PROGRESS
        progress((len/2-step), (len/2-1));
#endif
    }
}

