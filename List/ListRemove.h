#pragma once


//ɾ���Ϸ��ڵ�p����������ֵ
template <typename T> 
T List<T>::remove(NodePtr p)
{
	//���ݴ�ɾ���ڵ����ֵ���ٶ�T���Ϳ�ֱ�Ӹ�ֵ��
	T e = p->data; 

	p->pPrior->pNext = p->pNext; // ���
	p->pNext->pPrior = p->pPrior; // ǰ��

	// �ͷŽڵ�
	delete p;

	// ���¹�ģ
	_size--; 

	// ���ر��ݵ���ֵ
	return e; 
}