#pragma once

//�б��ʼ�����ڴ����б����ʱͳһ����
template <typename T> 
void List<T>::init() 
{ 
	//����ͷ�ڱ��ڵ�
	header = new Node<T>;

	//����β�ڱ��ڵ�
	trailer = new Node<T>;

	header->pNext = trailer; 
	header->pPrior = nullptr;

	trailer->pPrior = header; 
	trailer->pNext = nullptr;

	//��¼��ģ
	_size = 0;
}