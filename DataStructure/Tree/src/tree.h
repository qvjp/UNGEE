#ifndef __TREE_H
#define __TREE_H

#include "../../Common/src/types.h"

#define MAXSIZE 100

// 双亲表示法
struct PNode
{
    ElemType data;
    int parent;
};

struct PTree
{
    struct PNode node[MAXSIZE];
    int n;
};

// 孩子表示法
struct CNode2
{
    int child;
    struct CNode2* next;
};

struct CTree
{
    ElemType data;
    struct CNode* firstchild;
};

// 孩子兄弟表示法
struct CSNode
{
    ElemType data;
    struct CSNode *firstchild, *rightsibling;
};

#endif /* __TREE_H */
