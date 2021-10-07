#pragma once

// 向量归并排序
template <typename T>
void Vector<T>::mergeSort(size_t lo, size_t hi)
{
	// 单元素区间自然有序(递归终止条件)
	if (hi - lo < 2) 
		return;

	// 以中点为界
	int mi = (lo + hi) / 2;

	//分别排序
	mergeSort(lo, mi); 
	mergeSort(mi, hi);

	//归并
	merge(lo, mi, hi);
}