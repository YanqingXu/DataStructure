#pragma once

// �����±������
template <typename T> 
T& Vector<T>::operator[] (size_t r) 
{
	return _elem[r];
}

//����������ֵ
template <typename T> 
const T& Vector<T>::operator[] (size_t r) const 
{
	return _elem[r];
}