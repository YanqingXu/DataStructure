#pragma once

//�б�������
template <typename T> List<T>::~List()
{
	//����б�
	clear(); 
	
	// �ͷ�ͷ�ڱ��ڵ�
	delete header; 

	// �ͷ�β�ڱ��ڵ�
	delete trailer;
} 