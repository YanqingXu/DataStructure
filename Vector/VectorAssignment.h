#pragma once

//���
template <typename T> 
Vector<T>& Vector<T>::operator= (Vector<T> const& V) 
{ 
	//�ͷ�ԭ������
	if (_elem) 
		delete[] _elem; 

	//���帴��
	copyFrom(V._elem, 0, V.size());

	//���ص�ǰ��������ã��Ա���ʽ��ֵ
	return *this;
}