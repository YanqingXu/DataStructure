#pragma once

//��[lo, hi]���ҳ������
template <typename T>
size_t Vector<T>::max(size_t lo, size_t hi) 
{ 
	size_t idx = hi;

	//����ɨ��
	while (lo < hi--)
	{
		//�ϸ�Ƚ�,������max�ж��ʱ��֤�������ȣ�������֤selectionSort�ȶ�
		if (_elem[hi] > _elem[idx]) 
			idx = hi;
	}
		
	return idx;
}
