#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

void swap(struct D_SqList *l, int i, int j)
{
    int tmp;
    tmp = l->elem[j];
    l->elem[j] = l->elem[i];
    l->elem[i] = tmp;
}

void progress(int i, int len)
{
    char *bar = (char *)malloc(sizeof(char) * 100);
    for (int i = 0; i < 100; ++i)
    {
        bar[i] = '#';
    }
    int p = (int)((float)i/(float)len*100);
    int last = (int)((float)(i-1)/(float)len*100);
    if (p == last)
        return;
    printf("progress:[%s]%d%%>\r", bar+100-p, p);
    if (p == 100)
        printf("\n");
    fflush(stdout);
}
