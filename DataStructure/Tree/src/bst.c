#include "linked_binary_tree.h"
#include <stdlib.h>
#include <stdio.h>

// 二叉查找树的查找，找到返回值，找不到返回-1
ElemType Get(BTree t, ElemType key)
{
    if (!t)
    {
        return -1;
    }
    else if (key > t->data)
        return Get(t->rchild, key);
    else if (key < t->data)
        return Get(t->lchild, key);
    return t->data;
}

// 二叉查找树插入元素
Status Put(BTree *t, ElemType e)
{
    // printf("Put: %d ", e);
    if (!(*t))
    {
        (*t) = (BTree)malloc(sizeof(struct BTNode));
        (*t)->data = e;
        (*t)->rchild = NULL;
        (*t)->lchild = NULL;
        return OK;
    }
    else if (e == (*t)->data)
    {
        return ERROR;
    }
    else if (e > (*t)->data)
        return Put(&(*t)->rchild, e);
    else if (e < (*t)->data)
        return Put(&(*t)->lchild, e);
    return OK;
}

// 创建BST
Status InitBST(BTree *t, char *str)
{
    (*t) = NULL;
    while (*str)
    {
        Put(t, (int)*str++ - '0');
    }
    return OK;
}

struct BTNode* min(BTree *t)
{
    struct BTNode* min = (*t);
    while(min->lchild)
    {
            min = min->lchild;
    }
    return min;
};

// 删除结点
Status Remove(BTree *b, ElemType e)
{
    BTree t = (*b);
    if (!(t))
        return ERROR;
    BTree parent = (t);
    while (t)
    {
        if ((t)->data > e)
        {
            parent = (t);
            (t) = (t)->lchild;
        }
        else if ((t)->data < e)
        {
            parent = (t);
            (t) = (t)->rchild;
        }
        else
        {
            if ((t)->rchild && (t)->lchild)
            {
                if (!(t->rchild->lchild || t->rchild->rchild))
                {
                    t->rchild->lchild = t->lchild;
                    parent->rchild = t->rchild;
                }
                else
                {
                    struct BTNode *node = min((&(t)->rchild));
                    if (node == t->rchild)
                        node->rchild= node->rchild->rchild;
                    else
                        node->rchild = (t)->rchild;
                    node->lchild = (t)->lchild;
                    parent->rchild = node;
                }
            }
            else if ((t)->lchild)
            {
                if (parent->rchild == (t))
                    parent->rchild = (t)->lchild;
                else if (parent->lchild == (t))
                    parent->lchild = (t)->lchild;
            }
            else if ((t)->rchild)
            {
                if (parent->rchild == (t))
                    parent->rchild = (t)->rchild;
                else if (parent->lchild == (t))
                    parent->lchild = (t)->rchild;
            }
            else
            {
                if (parent->rchild == (t))
                    parent->rchild = NULL;
                else if (parent->lchild == (t))
                    parent->lchild = NULL;
            }
            return OK;
        }
    }
    return ERROR;
}

int main()
{
    BTree t = NULL;
    char *str = "31524967";
    InitBST(&t, str);
    Remove(&t, 1);
    inorder(t);
    printf("\n");
    return 0;
}
