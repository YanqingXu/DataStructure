#pragma once

//�����ռ䲻��ʱ����
template <typename T>
void Vector<T>::expand() 
{
	//��δ��Աʱ����������
	if (_size < _capacity) 
		return; 

	//��������С����
	if (_capacity < DEFAULT_CAPACITY)
		_capacity = DEFAULT_CAPACITY;

	//�����ӱ�
	T* oldElem = _elem;
	_elem = new T[_capacity <<= 1]; 

	//����ԭ�������ݣ�TΪ�������ͣ��������ظ�ֵ������'='��
	for (int i = 0; i < _size; i++)
		_elem[i] = oldElem[i];

	//�ͷ�ԭ�ռ�
	delete[] oldElem; 
}