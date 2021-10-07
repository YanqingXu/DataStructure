#pragma once

//向量空间不足时扩容
template <typename T>
void Vector<T>::expand() 
{
	//尚未满员时，不必扩容
	if (_size < _capacity) 
		return; 

	//不低于最小容量
	if (_capacity < DEFAULT_CAPACITY)
		_capacity = DEFAULT_CAPACITY;

	//容量加倍
	T* oldElem = _elem;
	_elem = new T[_capacity <<= 1]; 

	//复制原向量内容（T为基本类型，或已重载赋值操作符'='）
	for (int i = 0; i < _size; i++)
		_elem[i] = oldElem[i];

	//释放原空间
	delete[] oldElem; 
}