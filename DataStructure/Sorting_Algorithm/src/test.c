#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include <time.h>


// 打开注释可测试已排序序列再次排序所用时间
// #define SECOND


void test(struct D_SqList L, int len)
{
    int result = 2; // 正序
    if (len != L.length)
    {
        printf("FALSE! LENGTH NOT EQ!  %d -> %d\n\n", len, L.length);
        return;
    }
    for (int i = 0; i < L.length-1; i++)
    {
        if (L.elem[i] > L.elem[i+1])
        {
            result = 1; // 发现逆序
            break;
        }
    }
    if (result == 1)
        for (int i = 0; i < L.length-1; i++)
        {
            if (L.elem[i] < L.elem[i+1])
            {
                result = 0; //逆序里出现正序
                break;
            }
        }
    if (result == 1)
        printf("TRUE But INVERSE\n\n");
    else if (result == 2)
        printf("TRUE\n\n");
    else
        printf("FALSE\n\n");

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
    int NUM = 100;
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
    QuickSort(&L, 1);
    finish = clock();
    printf("%f seconds\n", (double)(finish - start) / CLOCKS_PER_SEC);
    fflush(stdout);
    test(L, NUM);

#ifdef SECOND
    start = clock();
    printf("Quick Sort Second:\n");
    QuickSort(&L, 0);
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
