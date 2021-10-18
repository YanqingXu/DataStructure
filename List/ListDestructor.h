#pragma once

//列表析构器
template <typename T> List<T>::~List()
{
	//清空列表
	clear(); 
	
	// 释放头哨兵节点
	delete header; 

	// 释放尾哨兵节点
	delete trailer;
} 