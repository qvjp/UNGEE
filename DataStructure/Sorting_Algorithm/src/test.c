#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include <time.h>


// 打开注释可测试已排序序列再次排序所用时间
#define SECOND


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
void fuck(struct D_SqList *L, int num, int max)
{

    InitList(L);
    for (int i = 1; i <= num; i++)
    {
        ListInsert(L, i, rand() % max);
    }
}

int main(int argc, char** argv)
{
    int NUM = 10;
    int MAX = 100;
    if (argc == 2)
    {
        NUM = atoi(argv[1]);
    }
    if (argc == 3)
    {
        NUM = atoi(argv[1]);
        MAX = atoi(argv[2]);
    }
    struct D_SqList L;
    srand(time(0));
    clock_t start, finish;
    printf("TEST BEGIN...\n");
    printf("THE TEST COLLECTION'S SIZE IS: %d, FROM 0 TO %d.\n\n", NUM, MAX);
    fflush(stdout);

    fuck(&L, NUM, MAX);
    start = clock();
    printf("Insertion Sort First:\n");
    InsertionSort(&L);
    finish = clock();
    printf("%f seconds\n", (double)(finish - start) / CLOCKS_PER_SEC);
    fflush(stdout);
    test(L,NUM);

#ifdef SECOND
    start = clock();
    printf("Insertion Sort Second:\n");
    InsertionSort(&L);
    finish = clock();
    printf("%f seconds\n", (double)(finish - start) / CLOCKS_PER_SEC);
    fflush(stdout);
    test(L,NUM);
#endif

    fuck(&L, NUM, MAX);
    start = clock();
    printf("Shell's Sort First:\n");
    ShellSort(&L);
    finish = clock();
    printf("%f seconds\n", (double)(finish - start) / CLOCKS_PER_SEC);
    fflush(stdout);
    test(L,NUM);

#ifdef SECOND
    start = clock();
    printf("Shell's Sort Second:\n");
    ShellSort(&L);
    finish = clock();
    printf("%f seconds\n", (double)(finish - start) / CLOCKS_PER_SEC);
    fflush(stdout);
    test(L,NUM);
#endif
    
    fuck(&L, NUM, MAX);
    start = clock();
    printf("Bubble Sort First:\n");
    BubbleSort(&L);
    finish = clock();
    printf("%f seconds\n", (double)(finish - start) / CLOCKS_PER_SEC);
    fflush(stdout);
    test(L,NUM);

#ifdef SECOND
    start = clock();
    printf("Bubble Sort Second:\n");
    BubbleSort(&L);
    finish = clock();
    printf("%f seconds\n", (double)(finish - start) / CLOCKS_PER_SEC);
    fflush(stdout);
    test(L,NUM);
#endif

    fuck(&L, NUM, MAX);
    start = clock();
    printf("Selection Sort First:\n");
    SelectionSort(&L);
    finish = clock();
    printf("%f seconds\n", (double)(finish - start) / CLOCKS_PER_SEC);
    fflush(stdout);
    test(L, NUM);

#ifdef SECOND
    start = clock();
    printf("Selection Sort Second:\n");
    SelectionSort(&L);
    finish = clock();
    printf("%f seconds\n", (double)(finish - start) / CLOCKS_PER_SEC);
    fflush(stdout);
    test(L, NUM);
#endif

    fuck(&L, NUM, MAX);
    start = clock();
    printf("Heap Sort First:\n");
    HeapSort(&L);
    finish = clock();
    printf("%f seconds\n", (double)(finish - start) / CLOCKS_PER_SEC);
    fflush(stdout);
    test(L, NUM);

#ifdef SECOND
    start = clock();
    printf("Heap Sort Second\n");
    HeapSort(&L);
    finish = clock();
    printf("%f seconds\n", (double)(finish - start) / CLOCKS_PER_SEC);
    fflush(stdout);
    test(L, NUM);
#endif

    fuck(&L, NUM, MAX);
    start = clock();
    printf("Quick Sort First:\n");
    QuickSort(&L);
    finish = clock();
    printf("%f seconds\n", (double)(finish - start) / CLOCKS_PER_SEC);
    fflush(stdout);
    test(L, NUM);

#ifdef SECOND
    start = clock();
    printf("Quick Sort Second:\n");
    QuickSort(&L);
    finish = clock();
    printf("%f seconds\n", (double)(finish - start) / CLOCKS_PER_SEC);
    fflush(stdout);
    test(L, NUM);
#endif


    fuck(&L, NUM, MAX);
    start = clock();
    printf("Merge Sort First:\n");
    MergeSort(&L);
    finish = clock();
    printf("%f seconds\n", (double)(finish - start) / CLOCKS_PER_SEC);
    fflush(stdout);
    test(L, NUM);

#ifdef SECOND
    start = clock();
    printf("Merge Sort Second:\n");
    MergeSort(&L);
    finish = clock();
    printf("%f seconds\n", (double)(finish - start) / CLOCKS_PER_SEC);
    fflush(stdout);
    test(L, NUM);
#endif

    fuck(&L, NUM, MAX);
    start = clock();
    printf("Radix Sort First:\n");
    RadixSort(&L);
    finish = clock();
    printf("%f seconds\n", (double)(finish - start) / CLOCKS_PER_SEC);
    fflush(stdout);
    test(L, NUM);


#ifdef SECOND
    start = clock();
    printf("Radix Sort Second:\n");
    RadixSort(&L);
    finish = clock();
    printf("%f seconds\n", (double)(finish - start) / CLOCKS_PER_SEC);
    fflush(stdout);
    test(L, NUM);
    return 0;
#endif
}
