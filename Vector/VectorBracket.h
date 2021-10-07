#pragma once

// 重载下标操作符
template <typename T> 
T& Vector<T>::operator[] (size_t r) 
{
	return _elem[r];
}

//仅限于做右值
template <typename T> 
const T& Vector<T>::operator[] (size_t r) const 
{
	return _elem[r];
}