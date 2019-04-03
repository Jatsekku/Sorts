#ifndef INTROSORT_HPP_
#define INTROSORT_HPP_
#include "HeapSort.hpp"
#include "InsertSort.hpp"
#include <math.h>
#include <stdio.h>

template <typename object_t>
static void iswap(object_t array[], int idx1, int idx2)
{
	object_t element_tmp = array[idx1];
	array[idx1] = array[idx2];
	array[idx2] = element_tmp;
}

template <typename object_t>
int isplit(object_t array[], int start_idx, int end_idx)
{
	object_t pivot_value;		//Creating variable, which contains pivot value
	int pivot_idx;				//Creating variable, which contains index of pivot
	int idx_tmp1, idx_tmp2;

	pivot_idx = start_idx + rand()%(end_idx - start_idx);	//Randomly pick pivot from given array
	pivot_value = array[pivot_idx];							//Assign pivot with element from given array
	swap(array, pivot_idx, end_idx);
	idx_tmp1 = start_idx;

	for(idx_tmp2 = start_idx; idx_tmp2 <= end_idx -1; idx_tmp2++)
	{
		if(array[idx_tmp2] < pivot_value)
		{
			swap(array, idx_tmp2, idx_tmp1);
			idx_tmp1++;
		}
	}
	swap(array, idx_tmp1, end_idx);
	return idx_tmp1;
}

template <typename object_t>
void _IntroSort(object_t array[], int start_idx, int end_idx, int max_depth )
{
    if ( start_idx < end_idx )
    {
        if( !max_depth  )
        {
            HeapSort(array, start_idx, end_idx);
            return;
        }
        int n = isplit(array, start_idx, end_idx);
        _IntroSort(array, start_idx, n-1, max_depth-1 );
        _IntroSort(array, n+1, end_idx, max_depth-1 );
    }
}

template <typename object_t>
void IntroSort(object_t array[], int start_idx, int end_idx )
{
	int n = start_idx - end_idx;
	int m = int(2*log(double(n)));
	_IntroSort<object_t>(array, start_idx, end_idx, m);
	//qS(array, start_idx, end_idx);
}

#endif /* INTROSORT_HPP_ */
