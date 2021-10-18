#pragma once

// ���б�����ʼ��λ��p�����Ϊn��������ѡ������
template <typename T> 
void List<T>::selectionSort(NodePtr p, size_t n) 
{
	NodePtr head = p->pPrior;
	NodePtr tail = p;

	//����������Ϊ(head, tail)
	for (size_t i = 0; i < n; i++)
		tail = tail->pNext;

	// �����ٻ�ʣ�����ڵ�֮ǰ���ڴ�����������
	while (1 < n) 
	{ 
		//�ҳ�����ߣ�����ʱ�������ȣ�
		NodePtr max = selectMax(head->pNext, n); 

		//����������������ĩβ����Ϊ���������µ���Ԫ�أ�
		insertAsNext(tail, remove(max));

		tail = tail->pNext; 
		n--;
	}
}