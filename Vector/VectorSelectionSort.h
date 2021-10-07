#pragma once

// 向量选择排序
template <typename T> 
void Vector<T>::selectionSort(size_t lo, size_t hi) 
{
	printf("\tselection sort [%3d, %3d)\n", lo, hi);
	while (lo < --hi)
	{
		//将[hi]与[lo, hi]中的最大者交换
		swap(_elem[max(lo, hi)], _elem[hi]);
	}
}