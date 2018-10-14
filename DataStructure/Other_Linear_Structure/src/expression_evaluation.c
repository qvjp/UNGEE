#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linked_stack.h"

void ToPostfix(char *e, char* post)
{
    int index = 0;
    int pop = 0;
    struct StackNode *stack;
    InitStack(&stack);
    for(;*e;)
    {
        pop = 0;
        if (*e > 47 && *e < 58) // 操作数直接输出
            post[index++] = *e;
        if (*e == 40)           // '('
            Push(&stack, *e);
        if (*e == 41)           // ')'
        {
            for (Pop(&stack, &pop); pop != 40; Pop(&stack, &pop))
            {
                post[index++] = pop;
            }
        }

        if (*e == 42 || *e == 43 || *e == 45 || *e ==47)   // * + - /
        {
            if(!StackEmpty(stack))  // 栈为空
            {
                Push(&stack, *e);
            }
            else
            {
                for (; (StackEmpty(stack) && pop != -1) ;)
                {
                    GetTopElem(stack, &pop);
                    switch (pop)
                    {
                        case 42:
                        case 47:
                            Pop(&stack, &pop);
                            post[index++] = pop;
                            break;
                        case 43:
                        case 45:
                            if (*e == 43 || *e == 45)
                            {
                                Pop(&stack, &pop);
                                post[index++] = pop;
                            }
                            else
                                pop = -1;
                            break;
                        default:
                            pop = -1;
                            break;
                    }

                }
                Push(&stack, *e);
            }
        }

        *e++;
    }
    // 全部出栈
    for (; StackEmpty(stack);)
    {
        Pop(&stack, &pop);
        post[index++] = pop;
    }
    post[index] = '\0';
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
    char *e = "1+2-1*((3+4)/5-6)+7";
    //char *e = "12+134+5/6-*-7+";
    char *post;
    post = malloc(sizeof(char)*strlen(e));
    ToPostfix(e, post);

    printf("中缀表达式为:%s\n", e);
    printf("后缀表达式为:%s\n", post);
    CalcPostfix(post, &a);
    printf("a: %d\n", a);
    return 0;
}
