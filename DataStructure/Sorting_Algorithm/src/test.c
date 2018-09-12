#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include <time.h>

#define NUM 100000
#define MAX 100

void test(struct D_SqList L, int len)
{
    if (len != L.length)
    {
        printf("FALSE! LENGTH NOT EQ!  %d -> %d\n\n", len, L.length);
        return;
    }
    for (int i = 0; i < L.length-1; i++)
    {
        if (L.elem[i] > L.elem[i+1])
        {
            printf("FALSE IN %d\n\n", i);
            return;
        }
    }
    printf("TRUE\n\n");
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

// 生成随机序列
void fuck(struct D_SqList *L)
{

    InitList(L);
    for (int i = 1; i <= NUM; i++)
    {
        ListInsert(L, i, rand() % MAX);
    }
}

int main()
{
    struct D_SqList L;
    srand(time(0));
    clock_t start, finish;
    printf("TEST BEGIN...\n");
    printf("THE TEST COLLECTION'S SIZE IS: %d, FROM 0 TO %d.\n\n", NUM, MAX);
    fflush(stdout);

    fuck(&L);
    start = clock();
    printf("Insertion Sort:\n");
    InsertionSort(&L);
    finish = clock();
    printf("%f seconds\n", (double)(finish - start) / CLOCKS_PER_SEC);
    fflush(stdout);
    test(L,NUM);

    fuck(&L);
    start = clock();
    printf("Shell's Sort\n");
    ShellSort(&L);
    finish = clock();
    printf("%f seconds\n", (double)(finish - start) / CLOCKS_PER_SEC);
    fflush(stdout);
    test(L,NUM);
    
    fuck(&L);
    start = clock();
    printf("Bubble Sort\n");
    BubbleSort(&L);
    finish = clock();
    printf("%f seconds\n", (double)(finish - start) / CLOCKS_PER_SEC);
    fflush(stdout);
    test(L,NUM);

    fuck(&L);
    start = clock();
    printf("Selection Sort\n");
    SelectionSort(&L);
    finish = clock();
    printf("%f seconds\n", (double)(finish - start) / CLOCKS_PER_SEC);
    fflush(stdout);
    test(L, NUM);

    fuck(&L);
    start = clock();
    printf("Heap Sort\n");
    HeapSort(&L);
    finish = clock();
    printf("%f seconds\n", (double)(finish - start) / CLOCKS_PER_SEC);
    fflush(stdout);
    test(L, NUM);

    fuck(&L);
    start = clock();
    printf("Quick Sort:\n");
    QuickSort(&L);
    finish = clock();
    printf("%f seconds\n", (double)(finish - start) / CLOCKS_PER_SEC);
    fflush(stdout);
    test(L, NUM);

    fuck(&L);
    start = clock();
    printf("Merge Sort\n");
    MergeSort(&L);
    finish = clock();
    printf("%f seconds\n", (double)(finish - start) / CLOCKS_PER_SEC);
    fflush(stdout);
    test(L, NUM);


    fuck(&L);
    start = clock();
    printf("Radix Sort\n");
    RadixSort(&L);
    finish = clock();
    printf("%f seconds\n", (double)(finish - start) / CLOCKS_PER_SEC);
    fflush(stdout);
    test(L, NUM);
    return 0;
}
