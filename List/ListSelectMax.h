#pragma once

//从起始于位置p的n个元素中选出最大者
template <typename T> 
NodePtr List<T>::selectMax(NodePtr p, size_t n) 
{
	//最大者暂定为首节点p
	NodePtr max = p; 

	//从首节点p出发，将后续节点逐一与max比较
	for (NodePtr cur = p; n > 0; n--, cur = cur->pNext)
	{
		// 更新最大元素位置记录
		if (cur->data > max->data)
		{
			max = cur;
		}
	}

	return max; //返回最大节点位置
}

template <typename T>
NodePtr List<T>::selectMax()
{
	return selectMax(header->pNext, _size);
}