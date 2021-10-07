#pragma once

// �������������򣨻����棩
template <typename T>
void Vector<T>::bubbleSort1(size_t lo, size_t hi) 
{
	//��������ɨ��
	while (lo < --hi) 
	{
		//����������Ԫ��
		for (size_t i = lo; i < hi; i++)
		{
			//�������򾭽���ʹ�ֲ�����
			if (_elem[i] > _elem[i + 1]) 
				swap(_elem[i], _elem[i + 1]); 
		}	
	}	
}

// ����������������ǰ��ֹ�棩
template <typename T> 
void Vector<T>::bubbleSort2(size_t lo, size_t hi) 
{
	for (bool sorted = false; sorted = !sorted; )
	{
		for (size_t i = lo; i < hi - 1; i++)
		{
			//��������
			if (_elem[i] > _elem[i + 1])
			{
				swap(_elem[i], _elem[i + 1]);
				sorted = false;
			}
				
			//������ʹ�ֲ����򡪡���Ȼ�����˻�����ȷ������������
		}	
	}
}

// ����������������Ծ�棩
template <typename T>
void Vector<T>::bubbleSort3(size_t lo, size_t hi)
{
	for (size_t last = --hi; lo < hi; hi = last)
	{
		for (size_t i = last = lo; i < hi; i++)
		{
			//�������򾭽���ʹ�ֲ�����
			if (_elem[i] > _elem[i + 1])
				swap(_elem[last = i], _elem[i + 1]); 
		}	
	}
}

// ��������������
template <typename T>
void Vector<T>::bubbleSort(size_t lo, size_t hi)
{
	switch (rand() % 3)
	{
		case 1:  bubbleSort1(lo, hi); break; //�������棩
		case 2:  bubbleSort2(lo, hi); break; //����ǰ��ֹ�棩
		default: bubbleSort3(lo, hi); break; //����Ծ�棩
	} 
	
	//���ѡ���㷨�Գ�ֲ��ԡ�ʵ��ʱ���Ӿ���������ص����ȷ��������
}
