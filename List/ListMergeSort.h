#pragma once

//列表的归并排序算法：对起始于位置p的n个元素排序
template <typename T> 
void List<T>::mergeSort(NodePtr& p, size_t n)
{ 
	//若待排序范围已足够小，则直接返回；否则...
	if (n < 2) 
		return; 

	//以中点为界，找到后子列表起点
	int m = n >> 1; 
	NodePtr q = p; 
	for (int i = 0; i < m; i++) 
		q = q->pNext; 

	//前、后子列表各分别排序
	mergeSort(p, m); 
	mergeSort(q, n - m);

	//归并
	p = merge(p, m, *this, q, n - m);
} //注意：排序后，p依然指向归并后区间的（新）起点