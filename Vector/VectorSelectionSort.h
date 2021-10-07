#pragma once

// ����ѡ������
template <typename T> 
void Vector<T>::selectionSort(size_t lo, size_t hi) 
{
	printf("\tselection sort [%3d, %3d)\n", lo, hi);
	while (lo < --hi)
	{
		//��[hi]��[lo, hi]�е�����߽���
		swap(_elem[max(lo, hi)], _elem[hi]);
	}
}