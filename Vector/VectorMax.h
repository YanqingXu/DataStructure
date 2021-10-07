#pragma once

//在[lo, hi]内找出最大者
template <typename T>
size_t Vector<T>::max(size_t lo, size_t hi) 
{ 
	size_t idx = hi;

	//逆向扫描
	while (lo < hi--)
	{
		//严格比较,故能在max有多个时保证后者优先，进而保证selectionSort稳定
		if (_elem[hi] > _elem[idx]) 
			idx = hi;
	}
		
	return idx;
}
