#pragma once

//�����б�����λ��p���n�assert: pΪ�Ϸ�λ�ã���������n-1����̽ڵ㣩
template <typename T> 
List<T>::List(NodePtr p, size_t n) 
{
	copyNodes(p, n); 
}

template <typename T> //���帴���б�L
List<T>::List(List<T> const& L) 
{ 
	copyNodes(L.first(), L._size); 
}

template <typename T> //����L���Ե�r�����n�assert: r+n <= L._size��
List<T>::List(List<T> const& L, size_t r, size_t n) 
{
	NodePtr p = L.first();

	while (0 < r--)
		p = p->pNext;

	copyNodes(p, n);
}