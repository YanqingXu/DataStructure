#pragma once

//�б��ڲ������������б�����λ��p���n��(p�Ϸ�����������n-1�����̽ڵ�)
template <typename T> 
void List<T>::copyNodes(NodePtr p, size_t n) 
{
	 //����ͷ��β�ڱ��ڵ㲢����ʼ��
	init();

	 //������p��n��������Ϊĩ�ڵ����
	while (n--) 
	{ 
		insertAsLast(p->data); 
		p = p->pNext; 
	}
}