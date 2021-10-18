#pragma once

//列表内部方法：复制列表中自位置p起的n项(p合法，且至少有n-1个真后继节点)
template <typename T> 
void List<T>::copyNodes(NodePtr p, size_t n) 
{
	 //创建头、尾哨兵节点并做初始化
	init();

	 //将起自p的n项依次作为末节点插入
	while (n--) 
	{ 
		insertAsLast(p->data); 
		p = p->pNext; 
	}
}