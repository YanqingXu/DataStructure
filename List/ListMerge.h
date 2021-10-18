#pragma once


//�����б�Ĺ鲢����ǰ�б�����p���n��Ԫ�أ����б�L����q���m��Ԫ�ع鲢
template <typename T> 
NodePtr List<T>::merge(List<T>& L, NodePtr p_node, size_t p_size, NodePtr q_node, size_t q_size)
{
	//�鲢֮��p���ܲ���ָ���׽ڵ㣬�����ȼ��䣬�Ա��ڷ���ǰ����
	NodePtr pp = p_node->pPrior;

	// q_node��δ���磨����mergeSort()�У�p_node��δ���磩֮ǰ
	while ((0 < q_size) && (q_node != p_node))
	{
		//��p_node��δ������v(p_node) <= v(q)����
		if ((0 < p_size) && (p_node->data <= q_node->data))
		{
			p_node = p_node->pNext;
			p_size--;
		}
		else 
		{
			insertAsNext(p_node, L.remove((q_node = q_node->pNext)->pPrior));
			q_size--;
		}
	}
		
	return pp->pNext; //���µ��׽ڵ�
}