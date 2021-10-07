#pragma once

constexpr size_t DEFAULT_CAPACITY = 5;

// ����ģ����
template <typename T>
class Vector { 

public:
	// ����Ϊc����ģΪs������Ԫ�س�ʼΪv
	Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0) 
	{
		_elem = new T[_capacity = c];
		for (_size = 0; _size < s; _elem[_size++] = v);
	}

	size_t max(size_t lo, size_t hi); // ѡȡ���Ԫ��
	void expand(); // �ռ䲻��ʱ����
	void shrink(); // װ�����ӹ�Сʱѹ��
	void copyFrom(T const* A, size_t lo, size_t hi); // ������������A[lo, hi)
	void bubbleSort(size_t lo, size_t hi); // ���������㷨
	void selectionSort(size_t lo, size_t hi); // ѡ�������㷨
	void merge(size_t lo, size_t mi, size_t hi); // �鲢�㷨
	void mergeSort(size_t lo, size_t hi); // �鲢�����㷨
	

	// ֻ�����ʽӿ�
	size_t size() const { return _size; } // ��ģ
	bool empty() const { return 0 == _size; } // �п�

	// ��д���ʽӿ�
	T& operator[] (size_t r); // �����±������������������������ʽ���ø�Ԫ��
	const T& operator[] (size_t r) const; // �����±������������������������ʽ���ø�Ԫ��
	Vector<T>& operator= (Vector<T> const&); // ���ظ�ֵ���������Ա�ֱ�ӿ�¡����

private:
	void bubbleSort1(size_t lo, size_t hi); // ���������㷨�������棩
	void bubbleSort2(size_t lo, size_t hi); // ���������㷨����ǰ��ֹ�棩
	void bubbleSort3(size_t lo, size_t hi); // ���������㷨����Ծ�棩

protected:
	T* _elem;
	size_t _capacity;
	size_t _size
};

#include "VectorImpl.h"