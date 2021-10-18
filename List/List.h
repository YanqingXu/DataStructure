#pragma once
#include "Node.h"


//�б�ģ����
template <typename T> 
class List
{
	using NodePtr = Node<T>::NodePtr;

protected:
	//�б���ʱ�ĳ�ʼ��
	void init();

	//������нڵ�
	size_t clear();

	//�����б�����λ��p���n��
	void copyNodes(NodePtr, size_t);

	//�鲢
	NodePtr merge(List<T>& L, NodePtr p_node, size_t p_size, NodePtr q_node, size_t q_size);

	//�Դ�p��ʼ������n���ڵ�鲢����
	void mergeSort(NodePtr& p, size_t n);

	//�Դ�p��ʼ������n���ڵ�ѡ������
	void selectionSort(NodePtr p, size_t n);

	//�Դ�p��ʼ������n���ڵ��������
	void insertionSort(NodePtr p, size_t n);

	//�Դ�p��ʼ������n���ڵ��������
	void radixSort(NodePtr, size_t);

public:
	// ���캯��
	List() { init(); } //Ĭ��

	List(List<T> const& L); //���帴���б�L

	List(List<T> const& L, size_t r, size_t n); //�����б�L���Ե�r�����n��

	List(NodePtr p, size_t n); //�����б�����λ��p���n��

	// ��������
	~List(); //�ͷţ�����ͷ��β�ڱ����ڵģ����нڵ�

 // ֻ�����ʽӿ�
	size_t size() const { return _size; } //��ģ
	bool empty() const { return _size <= 0; } //�п�

	NodePtr first() const { return header->pNext; } //�׽ڵ�λ��
	NodePtr last() const { return trailer->pPrior; } //ĩ�ڵ�λ��

	T& operator[] (size_t r) const; //���أ�֧��ѭ�ȷ��ʣ�Ч�ʵͣ�

	NodePtr selectMax(NodePtr p, size_t n); //��p����n-1�������ѡ�������
	NodePtr selectMax(); //���������

// ��д���ʽӿ�
	NodePtr insertAsFirst(T const& e); //��e�����׽ڵ����
	NodePtr insertAsLast(T const& e); //��e����ĩ�ڵ����

	NodePtr insertAsPrior(NodePtr p, T const& e); //��e����ĩ�ڵ����
	NodePtr insertAsNext(NodePtr p, T const& e); //��e����ĩ�ڵ����
	T remove(NodePtr p); //ɾ���Ϸ�λ��p���Ľڵ�,���ر�ɾ���ڵ�

private:
	size_t _size; // ��ģ
	NodePtr header; // ͷ�ڱ�
	NodePtr trailer; // β�ڱ�
};

#include "ListImpl.h"