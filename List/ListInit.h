#pragma once

//列表初始化，在创建列表对象时统一调用
template <typename T> 
void List<T>::init() 
{ 
	//创建头哨兵节点
	header = new Node<T>;

	//创建尾哨兵节点
	trailer = new Node<T>;

	header->pNext = trailer; 
	header->pPrior = nullptr;

	trailer->pPrior = header; 
	trailer->pNext = nullptr;

	//记录规模
	_size = 0;
}