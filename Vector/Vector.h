#pragma once

constexpr size_t DEFAULT_CAPACITY = 5;

template <typename T>
class Vector { //向量模板类

public:
	// 构造函数
	Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0) //容量为c、规模为s、所有元素初始为v
	{
		_elem = new T[_capacity = c];
		for (_size = 0; _size < s; _elem[_size++] = v);
	}

	void expand(); //空间不足时扩容
	void shrink(); //装填因子过小时压缩

	// 只读访问接口
	size_t size() const { return _size; } //规模
	bool empty() const { return 0 == _size; } //判空

protected:
	T* _elem;
	size_t _capacity;
	size_t _size
};

#include "VectorImpl.h"