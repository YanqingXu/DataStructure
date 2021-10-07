#pragma once

constexpr size_t DEFAULT_CAPACITY = 5;

// 向量模板类
template <typename T>
class Vector { 

public:
	// 容量为c、规模为s、所有元素初始为v
	Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0) 
	{
		_elem = new T[_capacity = c];
		for (_size = 0; _size < s; _elem[_size++] = v);
	}

	size_t max(size_t lo, size_t hi); // 选取最大元素
	void expand(); // 空间不足时扩容
	void shrink(); // 装填因子过小时压缩
	void copyFrom(T const* A, size_t lo, size_t hi); // 复制数组区间A[lo, hi)
	void bubbleSort(size_t lo, size_t hi); // 起泡排序算法
	void selectionSort(size_t lo, size_t hi); // 选择排序算法
	void merge(size_t lo, size_t mi, size_t hi); // 归并算法
	void mergeSort(size_t lo, size_t hi); // 归并排序算法
	

	// 只读访问接口
	size_t size() const { return _size; } // 规模
	bool empty() const { return 0 == _size; } // 判空

	// 可写访问接口
	T& operator[] (size_t r); // 重载下标操作符，可以类似于数组形式引用各元素
	const T& operator[] (size_t r) const; // 重载下标操作符，可以类似于数组形式引用各元素
	Vector<T>& operator= (Vector<T> const&); // 重载赋值操作符，以便直接克隆向量

private:
	void bubbleSort1(size_t lo, size_t hi); // 起泡排序算法（基本版）
	void bubbleSort2(size_t lo, size_t hi); // 起泡排序算法（提前终止版）
	void bubbleSort3(size_t lo, size_t hi); // 起泡排序算法（跳跃版）

protected:
	T* _elem;
	size_t _capacity;
	size_t _size
};

#include "VectorImpl.h"