#pragma once

// �б�ڵ�ģ���ࣨ��˫��������ʽʵ�֣�
template <typename T> 
struct Node 
{ 
	using NodePtr = Node<T>*;

	// ���캯��
	Node() 
	{
	} 
	
	// ���header��trailer�Ĺ���
	Node(T e, NodePtr p = nullptr, NodePtr n = nullptr) 
		: data(e), pPrior(p), pNext(n)
	{
	} 

	// ��Ա
	T data; 
	NodePtr pPrior = nullptr; // ǰ��
	NodePtr pNext = nullptr; // ���

// �����ӿ�:
	// ������ǰ�ڵ�֮ǰ�����½ڵ�
	NodePtr insertAsPrior(T const& e) 
	{
		//�����½ڵ�
		NodePtr node = new Node<T>(e, pPrior, this);

		//������������
		pPrior->pNext = node;
		pPrior = node;

		//�����½ڵ��λ��
		return node;
	}
	
	// ���浱ǰ�ڵ�֮������½ڵ�
	NodePtr insertAsNext(T const& e) 
	{
		// �����½ڵ�
		NodePtr node = new Node(e, this, pNext);

		// ������������
		pNext->pPrior = node;
		pNext = node;

		// �����½ڵ��λ��
		return node;
	}
};
