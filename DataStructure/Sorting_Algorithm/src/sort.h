#ifndef __SORT_H
#define __SORT_H

#include "../../Common/src/types.h"
#include "../../Linear_List/src/sequenticl_list.h"

void InsertionSort(struct D_SqList *l);
void ShellSort(struct D_SqList *l);
void BubbleSort(struct D_SqList *l);
void QuickSort(struct D_SqList *l);
void SelectionSort(struct D_SqList *l);
void HeapSort(struct D_SqList *l);
void MergeSort(struct D_SqList *l);
void RadixSort(struct D_SqList *l);

void progress(int i, int len);



#endif /* __SORT_H */
