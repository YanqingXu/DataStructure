#pragma once

template <typename T>
void Vector<T>::shrink()	//װ�����ӹ�Сʱѹ��������ռ�ռ�
{
	if (_capacity < DEFAULT_CAPACITY << 1) 
		return; //����������DEFAULT_CAPACITY����

	if (_size << 2 > _capacity) 
		return; //��25%Ϊ��

	T* oldElem = _elem;
	_elem = new T[_capacity >>= 1]; //��������

	for (int i = 0; i < _size; i++)
		_elem[i] = oldElem[i]; //����ԭ��������

	delete[] oldElem; //�ͷ�ԭ�ռ�
}