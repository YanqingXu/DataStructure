#pragma once
#include "Node.h"


//列表模板类
template <typename T> 
class List
{
	using NodePtr = Node<T>::NodePtr;

protected:
	//列表创建时的初始化
	void init();

	//清除所有节点
	size_t clear();

	//复制列表中自位置p起的n项
	void copyNodes(NodePtr, size_t);

	//归并
	NodePtr merge(List<T>& L, NodePtr p_node, size_t p_size, NodePtr q_node, size_t q_size);

	//对从p开始连续的n个节点归并排序
	void mergeSort(NodePtr& p, size_t n);

	//对从p开始连续的n个节点选择排序
	void selectionSort(NodePtr p, size_t n);

	//对从p开始连续的n个节点插入排序
	void insertionSort(NodePtr p, size_t n);

	//对从p开始连续的n个节点基数排序
	void radixSort(NodePtr, size_t);

public:
	// 构造函数
	List() { init(); } //默认

	List(List<T> const& L); //整体复制列表L

	List(List<T> const& L, size_t r, size_t n); //复制列表L中自第r项起的n项

	List(NodePtr p, size_t n); //复制列表中自位置p起的n项

	// 析构函数
	~List(); //释放（包含头、尾哨兵在内的）所有节点

 // 只读访问接口
	size_t size() const { return _size; } //规模
	bool empty() const { return _size <= 0; } //判空

	NodePtr first() const { return header->pNext; } //首节点位置
	NodePtr last() const { return trailer->pPrior; } //末节点位置

	T& operator[] (size_t r) const; //重载，支持循秩访问（效率低）

	NodePtr selectMax(NodePtr p, size_t n); //在p及其n-1个后继中选出最大者
	NodePtr selectMax(); //整体最大者

// 可写访问接口
	NodePtr insertAsFirst(T const& e); //将e当作首节点插入
	NodePtr insertAsLast(T const& e); //将e当作末节点插入

	NodePtr insertAsPrior(NodePtr p, T const& e); //将e当作末节点插入
	NodePtr insertAsNext(NodePtr p, T const& e); //将e当作末节点插入
	T remove(NodePtr p); //删除合法位置p处的节点,返回被删除节点

private:
	size_t _size; // 规模
	NodePtr header; // 头哨兵
	NodePtr trailer; // 尾哨兵
};

#include "ListImpl.h"