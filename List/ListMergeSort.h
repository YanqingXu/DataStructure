#pragma once

//�б�Ĺ鲢�����㷨������ʼ��λ��p��n��Ԫ������
template <typename T> 
void List<T>::mergeSort(NodePtr& p, size_t n)
{ 
	//��������Χ���㹻С����ֱ�ӷ��أ�����...
	if (n < 2) 
		return; 

	//���е�Ϊ�磬�ҵ������б����
	int m = n >> 1; 
	NodePtr q = p; 
	for (int i = 0; i < m; i++) 
		q = q->pNext; 

	//ǰ�������б���ֱ�����
	mergeSort(p, m); 
	mergeSort(q, n - m);

	//�鲢
	p = merge(p, m, *this, q, n - m);
} //ע�⣺�����p��Ȼָ��鲢������ģ��£����