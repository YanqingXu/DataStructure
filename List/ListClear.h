#pragma once

//����б�
template <typename T> 
size_t List<T>::clear()
{ 
	size_t oldSize = _size;

	//����ɾ���׽ڵ㣬ֱ���б���
	while (0 < _size) 
		remove(header->pNext);

	return oldSize;
}