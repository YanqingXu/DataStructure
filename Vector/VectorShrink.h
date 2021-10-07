#pragma once

//装填因子过小时压缩向量所占空间
template <typename T>
void Vector<T>::shrink()
{
	//不致收缩到DEFAULT_CAPACITY以下
	if (_capacity < DEFAULT_CAPACITY << 1) 
		return;

	//以25%为界
	if (_size << 2 > _capacity) 
		return;

	//容量减半
	T* oldElem = _elem;
	_elem = new T[_capacity >>= 1];

	//复制原向量内容
	for (int i = 0; i < _size; i++)
		_elem[i] = oldElem[i];

	//释放原空间
	delete[] oldElem;
}