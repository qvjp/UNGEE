#ifndef __SEQUENTIAL_BINARY_TREE_H
#define __SEQUENTIAL_BINARY_TREE_H

#include "../../Common/src/types.h"
#define MAXSIZE 100

struct BTree
{
    ElemType data[MAXSIZE];
    int length;
};

// 初始化二叉树
Status InitBTree(struct BTree* b);

// 先序遍历
Status preorder(struct BTree b, int n);

// 中序遍历
Status inorder(struct BTree b, int n);

// 后序遍历
Status postorder(struct BTree b, int n);

// 层次遍历
Status levelorder(struct BTree b);

// 获取二叉树高度
int BTreeDeepth(struct BTree t);

#endif /* __SEQUENTIAL_BINARY_TREE_H */
