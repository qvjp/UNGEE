#include "sequential_binary_tree.h"
#include <math.h>
#include <stdio.h>

Status InitBTree(struct BTree *t)
{
    int e;
    t->length = 0;
    printf("从上到下的顺序依次输入二叉树各个节点，空节点用0表示，以-1表示输入结束\n");
    while(1)
    {
        if (t->length == MAXSIZE)
            break;
        scanf("%d", &e);
        if (e == -1)
            break;
        t->data[t->length++] = e;
    }
    t->data[t->length] = -1;
    return OK;
}

int BTreeDeepth(struct BTree t)
{
     return log(t.length + 1)/log(2);
}

Status ShowBTree(struct BTree t)
{
    struct flag
    {
        int flag;
        int sec;
    };
    struct flag flag={1, 1};
    int h = BTreeDeepth(t);
    for (int i = 0; i < t.length; i++)
    {
        if (i == 0)
        {
            for (int j = 0; j <= (int)pow(2, h-1)-1; j++)
                printf(" ");
        }
        if (i == flag.flag)
        {
            printf("\n");
            h--;
            //printf("H: %d\n", h);
            flag.flag = flag.flag + flag.sec * 2;
            flag.sec *= 2;
            for (int j = 0; j <= (int)pow(2, h-1)-1; j++)
                printf(" ");
        }
        if (t.data[i] == 0)
            printf(" ");
        else
            printf("%d", t.data[i]);
        if (i+1 != flag.flag)
        for (int j = 0; j < (int)pow(2,h)-1; j++)
        {
            // printf("-");
            printf(" ");
        }
    }
    printf("\n\n");
    return OK;
}
Status preorder(struct BTree b, int n)
{
    if (!(b.data[n] == 0 || b.data[n] == -1))
    {
        printf("%d ", b.data[n]);
        preorder(b, 2*n+1);
        preorder(b, 2*n+2);
    }
    return OK;
}
Status inorder(struct BTree b, int n)
{
    if (!(b.data[n] == 0 || b.data[n] == -1))
    {
        inorder(b, 2*n+1);
        printf("%d ", b.data[n]);
        inorder(b, 2*n+2);
    }
    return OK;
}

Status postorder(struct BTree b, int n)
{
    if (!(b.data[n] == 0 || b.data[n] == -1))
    {
        postorder(b, 2*n+1);
        postorder(b, 2*n+2);
        printf("%d ", b.data[n]);
    }
    return OK;
}

Status levelorder(struct BTree b)
{
    for (int i = 0; i < b.length; i++)
    {
        printf("%d ", b.data[i]);
    }
    printf("\n");
    return OK;
}

int main()
{
    struct BTree t;
    InitBTree(&t);
    ShowBTree(t);
    printf("先序遍历\n");
    preorder(t, 0);
    printf("\n中序遍历\n");
    inorder(t, 0);
    printf("\n后序遍历\n");
    postorder(t, 0);
    printf("\n层次遍历\n");
    levelorder(t);

    printf("\n");
    return 0;
}
