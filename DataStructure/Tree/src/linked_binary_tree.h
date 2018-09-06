#ifndef __SEQUENTIAL_BINARY_TREE_H
#define __SEQUENTIAL_BINARY_TREE_H

#include "../../Common/src/types.h"

struct BTNode
{
    ElemType data;
    struct BTNode* lchild;
    struct BTNode* rchild;
};

typedef struct BTNode *BTree;

// 初始化二叉树
void InitBTree(BTree* b, char** str);

// 先序遍历
Status preorder(BTree b);

// 中序遍历
Status inorder(BTree b);

// 后序遍历
Status postorder(BTree b);

// 获取二叉树高度
int BTreeDepth(BTree t);

#endif /* __SEQUENTIAL_BINARY_TREE_H */
