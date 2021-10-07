#pragma once

// �������������䣩�Ĺ鲢([lo, mi)��[mi, hi)��������lo < mi < hi)
template <typename T> 
void Vector<T>::merge(size_t lo, size_t mi, size_t hi)
{ 
	// pAll[0, hi - lo) = _elem[lo, hi)
	T* pAll = _elem + lo;

	// pPrior[0, lb) <-- _elem[lo, mi)
	size_t lb = mi - lo; 
	T* pPrior = new T[lb];

	// ������pAll��ǰ׺
	for (size_t i = 0; i < lb; i++) 
		pPrior[i] = pAll[i];

	// pPosterior[0, lc) = _elem[mi, hi)
	size_t lc = hi - mi; 
	T* pPosterior = _elem + mi; 

	size_t j = 0, k = 0;

	// �����رȽ�pPrior��pPosterior����Ԫ��,����С�߹���pAll��
	size_t i = 0;
	while ((j < lb) && (k < lc))
		pAll[i++] = (pPrior[j] <= pPosterior[k]) ? pPrior[j++] : pPosterior[k++];

	// ��pPosterior�Ⱥľ�����pPrior����ĺ�׺����pAll��
	while (j < lb) 
		pAll[i++] = pPrior[j++];

	// ��pPrior�Ⱥľ�����pPosterior����ĺ�׺����pAll��
	while (k < lc)
		pAll[i++] = pPrior[k++];

	// �ͷ���ʱ�ռ䣺mergeSort()�����У���α�����෴����new/delete��
	delete[] pPrior;
}
