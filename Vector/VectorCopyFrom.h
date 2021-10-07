#pragma once

//元素类型
template <typename T> 
void Vector<T>::copyFrom(T const* A, size_t lo, size_t hi) 
{
	//以数组区间A[lo, hi)为蓝本复制向量
	_elem = new T[_capacity = 2 * (hi - lo)];
	
	//分配空间，规模清零
	_size = 0; 

	//A[lo, hi)内的元素逐一复制至_elem[0, hi - lo)
	while (lo < hi) 
		_elem[_size++] = A[lo++];
}