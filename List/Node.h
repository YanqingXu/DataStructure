#pragma once

// 列表节点模板类（以双向链表形式实现）
template <typename T> 
struct Node 
{ 
	using NodePtr = Node<T>*;

	// 构造函数
	Node() 
	{
	} 
	
	// 针对header和trailer的构造
	Node(T e, NodePtr p = nullptr, NodePtr n = nullptr) 
		: data(e), pPrior(p), pNext(n)
	{
	} 

	// 成员
	T data; 
	NodePtr pPrior = nullptr; // 前驱
	NodePtr pNext = nullptr; // 后继

// 操作接口:
	// 紧靠当前节点之前插入新节点
	NodePtr insertAsPrior(T const& e) 
	{
		//创建新节点
		NodePtr node = new Node<T>(e, pPrior, this);

		//设置正向链接
		pPrior->pNext = node;
		pPrior = node;

		//返回新节点的位置
		return node;
	}
	
	// 紧随当前节点之后插入新节点
	NodePtr insertAsNext(T const& e) 
	{
		// 创建新节点
		NodePtr node = new Node(e, this, pNext);

		// 设置逆向链接
		pNext->pPrior = node;
		pNext = node;

		// 返回新节点的位置
		return node;
	}
};
