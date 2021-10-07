#pragma once

//װ�����ӹ�Сʱѹ��������ռ�ռ�
template <typename T>
void Vector<T>::shrink()
{
	//����������DEFAULT_CAPACITY����
	if (_capacity < DEFAULT_CAPACITY << 1) 
		return;

	//��25%Ϊ��
	if (_size << 2 > _capacity) 
		return;

	//��������
	T* oldElem = _elem;
	_elem = new T[_capacity >>= 1];

	//����ԭ��������
	for (int i = 0; i < _size; i++)
		_elem[i] = oldElem[i];

	//�ͷ�ԭ�ռ�
	delete[] oldElem;
}