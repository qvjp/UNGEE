#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned long f1(int n)
{
    if (n == 1 || n == 0)
    {
        return 1;
    }
    return f1(n - 1) + f1(n - 2);
}

unsigned long f2(int n)
{
    if (n == 0)
        return 1;
    unsigned long result = 1;
    unsigned long l[2] = {0,0};
    for (int i = 1; i <= n; i++)
    {
        l[0] = result;
        result += l[1];
        l[1] = l[0];
    }
    return result;
}

int main()
{
    int num = 35;
    srand(time(0));
    clock_t start, finish;

    start = clock();
    //for (int i = 0; i < num; i++)
    printf("%d %lu \n", num, f1(num));
    finish = clock();
    printf("Recursive: %f seconds\n", (double)(finish - start) / CLOCKS_PER_SEC);

    start = clock();
    //for (int i = 0; i < num; i++)
    printf("%d %lu \n", num, f2(num));
    finish = clock();
    printf("Loop: %f seconds\n", (double)(finish - start) / CLOCKS_PER_SEC);
    return 0;
}
