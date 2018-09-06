#ifndef __THREAD_BINARY_TREE_H
#define __THREAD_BINARY_TREE_H

#include "../../Common/src/types.h"

struct ThreadNode
{
    ElemType data;
    struct ThreadNode *lchild, *rchild;
    int ltag, rtag;
};

typedef struct ThreadNode *ThreadTree;


#endif /* __THREAD_BINARY_TREE_H */
