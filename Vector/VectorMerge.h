#pragma once

// 有序向量（区间）的归并([lo, mi)和[mi, hi)各自有序，lo < mi < hi)
template <typename T> 
void Vector<T>::merge(size_t lo, size_t mi, size_t hi)
{ 
	// pAll[0, hi - lo) = _elem[lo, hi)
	T* pAll = _elem + lo;

	// pPrior[0, lb) <-- _elem[lo, mi)
	size_t lb = mi - lo; 
	T* pPrior = new T[lb];

	// 复制自pAll的前缀
	for (size_t i = 0; i < lb; i++) 
		pPrior[i] = pAll[i];

	// pPosterior[0, lc) = _elem[mi, hi)
	size_t lc = hi - mi; 
	T* pPosterior = _elem + mi; 

	size_t j = 0, k = 0;

	// 反复地比较pPrior、pPosterior的首元素,将更小者归入pAll中
	size_t i = 0;
	while ((j < lb) && (k < lc))
		pAll[i++] = (pPrior[j] <= pPosterior[k]) ? pPrior[j++] : pPosterior[k++];

	// 若pPosterior先耗尽，则将pPrior残余的后缀归入pAll中
	while (j < lb) 
		pAll[i++] = pPrior[j++];

	// 若pPrior先耗尽，则将pPosterior残余的后缀归入pAll中
	while (k < lc)
		pAll[i++] = pPrior[k++];

	// 释放临时空间：mergeSort()过程中，如何避免此类反复的new/delete？
	delete[] pPrior;
}
