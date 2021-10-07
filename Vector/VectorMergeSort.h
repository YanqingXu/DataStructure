#pragma once

// �����鲢����
template <typename T>
void Vector<T>::mergeSort(size_t lo, size_t hi)
{
	// ��Ԫ��������Ȼ����(�ݹ���ֹ����)
	if (hi - lo < 2) 
		return;

	// ���е�Ϊ��
	int mi = (lo + hi) / 2;

	//�ֱ�����
	mergeSort(lo, mi); 
	mergeSort(mi, hi);

	//�鲢
	merge(lo, mi, hi);
}