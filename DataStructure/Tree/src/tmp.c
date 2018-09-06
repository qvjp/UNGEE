#include <stdio.h>

int FUCK1(char **str)
{
    printf("FUCK1\n");
    while(**str)
    {
        printf("%c ", **str);
        (*str)++;
        if (**str == '#')
            break;
    }
    return 0;
}

int FUCK2(char **str)
{
    printf("FUCK2\n");
    while(**str)
    {
        printf("%c ", **str);
        (*str)++;
    }
    return 0;
}

int FUCK(char** str)
{
    char ch = *(*str)++;
    if (ch != '#')
    {
        printf("%c ", ch);
        FUCK1(&(*str));
        FUCK2(&(*str));
    }
    return 0;
    
}

int main()
{
    char *str = "HE#LLO#";
    FUCK(&str);
    return 0;
}
