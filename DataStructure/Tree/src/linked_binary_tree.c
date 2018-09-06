#include "linked_binary_tree.h"
#include <stdlib.h>
#include <stdio.h>
#include "../../Other_Linear_Structure/src/linked_queue.h"


// 初始化二叉树
void InitBTree(BTree* b, char **str)
{
    char ch = *(*str)++;
    if (ch != '#')
    {
        (*b) = (struct BTNode*)malloc(sizeof(struct BTNode));
        (*b)->data = ch;
        InitBTree(&(*b)->lchild, str);
        InitBTree(&(*b)->rchild, str);
    }
    else
    {
        (*b) = NULL;
    }
}

// 先序遍历
Status preorder(BTree b)
{
    if (b)
    {
        printf("%d ", b->data);
        preorder(b->lchild);
        preorder(b->rchild);
    }
    return OK;
}


// 中序遍历
Status inorder(BTree b)
{
    if (b)
    {
        inorder(b->lchild);
        printf("%d ", b->data);
        inorder(b->rchild);
    }
    return OK;
}

// 后序遍历
Status postorder(BTree b)
{
    if (b)
    {
        postorder(b->lchild);
        postorder(b->rchild);
        printf("%d ", b->data);
    }
    return OK;
}

/* TODO:
Status levelorder(BTree b)
{
    struct Queue* q;
    InitQueue(&q);
    Put(&q, b);
}
*/

// 获取二叉树高度
int BTreeDepth(BTree t)
{
    int d = 0, dl = 0, dr = 0;
    if (t)
    {
        dl = BTreeDepth(t->lchild);
        dr = BTreeDepth(t->rchild);
        d = (dl > dr ? dl : dr) + 1;
    }
    return d;
}

/*
int main()
{
    char *tree = "ABC##D##EF##H##";
    BTree b;
    InitBTree(&b, &tree);
    preorder(b);
    printf("\n");
    inorder(b);
    printf("\n");
    postorder(b);
    printf("\n");
    printf("Depth: %d\n", BTreeDepth(b));
    return 0;
}
*/
