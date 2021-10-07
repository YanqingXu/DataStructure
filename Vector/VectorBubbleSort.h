#pragma once

// 向量的起泡排序（基本版）
template <typename T>
void Vector<T>::bubbleSort1(size_t lo, size_t hi) 
{
	//反复起泡扫描
	while (lo < --hi) 
	{
		//逐个检查相邻元素
		for (size_t i = lo; i < hi; i++)
		{
			//若逆序，则经交换使局部有序
			if (_elem[i] > _elem[i + 1]) 
				swap(_elem[i], _elem[i + 1]); 
		}	
	}	
}

// 向量的起泡排序（提前终止版）
template <typename T> 
void Vector<T>::bubbleSort2(size_t lo, size_t hi) 
{
	for (bool sorted = false; sorted = !sorted; )
	{
		for (size_t i = lo; i < hi - 1; i++)
		{
			//若逆序，则
			if (_elem[i] > _elem[i + 1])
			{
				swap(_elem[i], _elem[i + 1]);
				sorted = false;
			}
				
			//经交换使局部有序——当然，至此还不能确定已整体有序
		}	
	}
}

// 向量的起泡排序（跳跃版）
template <typename T>
void Vector<T>::bubbleSort3(size_t lo, size_t hi)
{
	for (size_t last = --hi; lo < hi; hi = last)
	{
		for (size_t i = last = lo; i < hi; i++)
		{
			//若逆序，则经交换使局部有序
			if (_elem[i] > _elem[i + 1])
				swap(_elem[last = i], _elem[i + 1]); 
		}	
	}
}

// 向量的起泡排序
template <typename T>
void Vector<T>::bubbleSort(size_t lo, size_t hi)
{
	switch (rand() % 3)
	{
		case 1:  bubbleSort1(lo, hi); break; //（基本版）
		case 2:  bubbleSort2(lo, hi); break; //（提前终止版）
		default: bubbleSort3(lo, hi); break; //（跳跃版）
	} 
	
	//随机选择算法以充分测试。实用时可视具体问题的特点灵活确定或扩充
}
