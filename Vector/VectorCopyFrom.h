#pragma once

//Ԫ������
template <typename T> 
void Vector<T>::copyFrom(T const* A, size_t lo, size_t hi) 
{
	//����������A[lo, hi)Ϊ������������
	_elem = new T[_capacity = 2 * (hi - lo)];
	
	//����ռ䣬��ģ����
	_size = 0; 

	//A[lo, hi)�ڵ�Ԫ����һ������_elem[0, hi - lo)
	while (lo < hi) 
		_elem[_size++] = A[lo++];
}