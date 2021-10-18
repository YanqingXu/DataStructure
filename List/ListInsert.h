#pragma once

//e当作首节点插入
template <typename T> 
NodePtr List<T>::insertAsFirst(T const& e)
{
	_size++; 
	return header->insertAsNext(e);
} 

//e当作末节点插入
template <typename T> 
NodePtr List<T>::insertAsLast(T const& e)
{
	_size++; 
	return trailer->insertAsPrior(e);
}

//e当作p的后继插入（After）
template <typename T> 
NodePtr List<T>::insertAsPrior(NodePtr p, T const& e)
{
	_size++; 
	return p->insertAsNext(e);
} 

//e当作p的前驱插入（Before）
template <typename T> 
NodePtr List<T>::insertAsNext(NodePtr p, T const& e)
{
	_size++; 
	return p->insertAsPrior(e);
} 
