#pragma once

//深复制
template <typename T> 
Vector<T>& Vector<T>::operator= (Vector<T> const& V) 
{ 
	//释放原有内容
	if (_elem) 
		delete[] _elem; 

	//整体复制
	copyFrom(V._elem, 0, V.size());

	//返回当前对象的引用，以便链式赋值
	return *this;
}