#ifndef __SEQUENTICL_SEARCH_H
#define __SEQUENTICL_SEARCH_H

#include "../../Linear_List/src/sequenticl_list.h" // struct D_SqList

#define MAXSIZE 100

struct Block
{
    ElemType elem[MAXSIZE];
    int length;
};

// 不设置哨兵的顺序查找
int SeqSearch1(struct D_SqList l, ElemType key);

// 设置哨兵的顺序查找
int SeqSearch2(struct D_SqList l, ElemType key);

// 对已排序序列顺序查找
int SeqedSearch(struct D_SqList l, int flag, ElemType key);

// 二分查找
int BinarySearch(struct D_SqList l, int flag, ElemType key);

// 分块查找
// b为已分好的块
// index为索引数组
// p q分别时结果所在的块下标和在块内的下标
Status BlockSearch(struct Block *b, int *index, ElemType key, int *p, int *q);

#endif /* __SEQUENTICL_SEARCH_H */
