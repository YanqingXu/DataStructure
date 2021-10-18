#pragma once

//����ʼ��λ��p��n��Ԫ����ѡ�������
template <typename T> 
NodePtr List<T>::selectMax(NodePtr p, size_t n) 
{
	//������ݶ�Ϊ�׽ڵ�p
	NodePtr max = p; 

	//���׽ڵ�p�������������ڵ���һ��max�Ƚ�
	for (NodePtr cur = p; n > 0; n--, cur = cur->pNext)
	{
		// �������Ԫ��λ�ü�¼
		if (cur->data > max->data)
		{
			max = cur;
		}
	}

	return max; //�������ڵ�λ��
}

template <typename T>
NodePtr List<T>::selectMax()
{
	return selectMax(header->pNext, _size);
}