#ifndef __SORT_H
#define __SORT_H

// 是否显示进度条
// #define PROGRESS

#include "../../Common/src/types.h"
#include "../../Linear_List/src/sequenticl_list.h"

void InsertionSort(struct D_SqList *l);
void ShellSort(struct D_SqList *l);
void BubbleSort(struct D_SqList *l);

/**
 * flag 非0是由小到大
 */
void QuickSort(struct D_SqList *l, int flag);
void SelectionSort(struct D_SqList *l);
void HeapSort(struct D_SqList *l);
void MergeSort(struct D_SqList *l);
void RadixSort(struct D_SqList *l);

void progress(int i, int len);

void swap(struct D_SqList *l, int i, int j);


#endif /* __SORT_H */
