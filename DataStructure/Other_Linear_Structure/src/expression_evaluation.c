#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linked_stack.h"

void ToPostfix(char **e)
{
    
}

void CalcPostfix(char *e, int *a)
{
    struct StackNode *stack;
    int x = 0;
    int y = 0;
    InitStack(&stack);
    char *expression = malloc(sizeof(strlen(e)));
    strcpy(expression, e);
    while (*expression)
    {
        if (*expression >= '1' && *expression <= '9')
        {
            x = *expression - '0';
            Push(&stack, x);
        }
        else if (*expression == '+' || *expression == '-' ||
                *expression == '*' || *expression == '/')
        {
            Pop(&stack, &y); 
            Pop(&stack, &x); 
            switch (*expression)
            {
                case '+':
                {
                    Push(&stack, x + y);
                    break;
                }
                case '-':
                {
                    Push(&stack, x - y);
                    break;
                }
                case '*':
                {
                    Push(&stack, x * y);
                    break;
                }
                case '/':
                {
                    Push(&stack, x / y);
                    break;
                }
            }
        }
        else
        {
            exit(ERROR);
        }
        *expression++;
    }
    Pop(&stack, &x);
    *a = x;
}

int main()
{
    printf("Hello, world\n");
    int a = 0;
    char *e = "125+*";
    CalcPostfix(e, &a);
    printf("a: %d\n", a);
    return 0;
}
