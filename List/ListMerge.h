#pragma once


//有序列表的归并：当前列表中自p起的n个元素，与列表L中自q起的m个元素归并
template <typename T> 
NodePtr List<T>::merge(List<T>& L, NodePtr p_node, size_t p_size, NodePtr q_node, size_t q_size)
{
	//归并之后p可能不再指向首节点，故需先记忆，以便在返回前更新
	NodePtr pp = p_node->pPrior;

	// q_node尚未出界（或在mergeSort()中，p_node尚未出界）之前
	while ((0 < q_size) && (q_node != p_node))
	{
		//若p_node尚未出界且v(p_node) <= v(q)，则
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
		
	return pp->pNext; //更新的首节点
}