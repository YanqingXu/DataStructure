#pragma once


//删除合法节点p，返回其数值
template <typename T> 
T List<T>::remove(NodePtr p)
{
	//备份待删除节点的数值（假定T类型可直接赋值）
	T e = p->data; 

	p->pPrior->pNext = p->pNext; // 后继
	p->pNext->pPrior = p->pPrior; // 前驱

	// 释放节点
	delete p;

	// 更新规模
	_size--; 

	// 返回备份的数值
	return e; 
}