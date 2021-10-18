#pragma once

//对列表中起始于位置p、宽度为n的区间做插入排序
template <typename T>
void List<T>::insertionSort(NodePtr p, size_t n) 
{
	//逐一为各节点,查找适当的位置并插入
	for (int r = 0; r < n; r++) 
	{ 
		insertAsPrior(search(p->data, r, p), p->data);
		p = p->pNext;

		//转向下一节点
		remove(p->pPrior); 
	}
}