#pragma once

//清空列表
template <typename T> 
size_t List<T>::clear()
{ 
	size_t oldSize = _size;

	//反复删除首节点，直至列表变空
	while (0 < _size) 
		remove(header->pNext);

	return oldSize;
}