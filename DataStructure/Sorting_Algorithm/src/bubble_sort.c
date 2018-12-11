#include <stdio.h>
#include "sort.h"

void BubbleSort(struct D_SqList *l)
{
    int len = l->length;
    Status flag = 1;  /* flag用来作为标记，为使已排好序的序列不再进行排序*/
    for (int i = 0; i < len - 1 && flag; i++) /* 若flag不为1则退出循环 */
    {
        flag = 0;
        for (int j = 0; j < len - i - 1; j++)
        {
            if (l->elem[j] > l->elem[j + 1])
            {
                swap(l, j, j+1);
                flag = 1;
            }
        }
#ifdef PROGRESS
        progress(i, len-2);
#endif
    }
}

