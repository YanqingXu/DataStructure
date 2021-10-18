#pragma once

typedef unsigned int U; //约定：类型T或就是U；或可转换为U，并依此定序

//对列表中起始于位置p、宽度为n的区间做基数排序
template <typename T> 
void List<T>::radixSort(NodePtr p, int n)
{
	NodePtr head = p->pPrior; 
	NodePtr tail = p;

	// 待排序区间为(head, tail)
	for (int i = 0; i < n; i++) 
		tail = tail->pNext;

	//以下反复地,根据当前基数位，将所有节点,分拣为后缀（1）与前缀（0）
	for (U radixBit = 0x1; radixBit && (p = head); radixBit <<= 1)
		for (int i = 0; i < n; i++) 
			radixBit& U(p->pNext->data) ? 
			insertAsNext(tail, remove(p->pNext)) : p = p->pNext;
}