#pragma once

// 对列表中起始于位置p、宽度为n的区间做选择排序
template <typename T> 
void List<T>::selectionSort(NodePtr p, size_t n) 
{
	NodePtr head = p->pPrior;
	NodePtr tail = p;

	//待排序区间为(head, tail)
	for (size_t i = 0; i < n; i++)
		tail = tail->pNext;

	// 在至少还剩两个节点之前，在待排序区间内
	while (1 < n) 
	{ 
		//找出最大者（歧义时后者优先）
		NodePtr max = selectMax(head->pNext, n); 

		//将其移至无序区间末尾（作为有序区间新的首元素）
		insertAsNext(tail, remove(max));

		tail = tail->pNext; 
		n--;
	}
}