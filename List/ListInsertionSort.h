#pragma once

//���б�����ʼ��λ��p�����Ϊn����������������
template <typename T>
void List<T>::insertionSort(NodePtr p, size_t n) 
{
	//��һΪ���ڵ�,�����ʵ���λ�ò�����
	for (int r = 0; r < n; r++) 
	{ 
		insertAsPrior(search(p->data, r, p), p->data);
		p = p->pNext;

		//ת����һ�ڵ�
		remove(p->pPrior); 
	}
}