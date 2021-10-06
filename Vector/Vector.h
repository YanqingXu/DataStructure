#pragma once

constexpr size_t DEFAULT_CAPACITY = 5;

template <typename T>
class Vector { //����ģ����

public:
	// ���캯��
	Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0) //����Ϊc����ģΪs������Ԫ�س�ʼΪv
	{
		_elem = new T[_capacity = c];
		for (_size = 0; _size < s; _elem[_size++] = v);
	}

	void expand(); //�ռ䲻��ʱ����
	void shrink(); //װ�����ӹ�Сʱѹ��

	// ֻ�����ʽӿ�
	size_t size() const { return _size; } //��ģ
	bool empty() const { return 0 == _size; } //�п�

protected:
	T* _elem;
	size_t _capacity;
	size_t _size
};

#include "VectorImpl.h"