#pragma once

typedef unsigned int U; //Լ��������T�����U�����ת��ΪU�������˶���

//���б�����ʼ��λ��p�����Ϊn����������������
template <typename T> 
void List<T>::radixSort(NodePtr p, int n)
{
	NodePtr head = p->pPrior; 
	NodePtr tail = p;

	// ����������Ϊ(head, tail)
	for (int i = 0; i < n; i++) 
		tail = tail->pNext;

	//���·�����,���ݵ�ǰ����λ�������нڵ�,�ּ�Ϊ��׺��1����ǰ׺��0��
	for (U radixBit = 0x1; radixBit && (p = head); radixBit <<= 1)
		for (int i = 0; i < n; i++) 
			radixBit& U(p->pNext->data) ? 
			insertAsNext(tail, remove(p->pNext)) : p = p->pNext;
}