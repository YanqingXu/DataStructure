#pragma once

//e�����׽ڵ����
template <typename T> 
NodePtr List<T>::insertAsFirst(T const& e)
{
	_size++; 
	return header->insertAsNext(e);
} 

//e����ĩ�ڵ����
template <typename T> 
NodePtr List<T>::insertAsLast(T const& e)
{
	_size++; 
	return trailer->insertAsPrior(e);
}

//e����p�ĺ�̲��루After��
template <typename T> 
NodePtr List<T>::insertAsPrior(NodePtr p, T const& e)
{
	_size++; 
	return p->insertAsNext(e);
} 

//e����p��ǰ�����루Before��
template <typename T> 
NodePtr List<T>::insertAsNext(NodePtr p, T const& e)
{
	_size++; 
	return p->insertAsPrior(e);
} 
