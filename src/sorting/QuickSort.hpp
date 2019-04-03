#ifndef QUICKSORT_HPP_
#define QUICKSORT_HPP_

template <typename object_t>
static void swap(object_t array[], int idx1, int idx2)		//Swapping two choosen elements of array
{
	object_t element_tmp = array[idx1];
	array[idx1] = array[idx2];
	array[idx2] = element_tmp;
}


template <typename object_t>
void QuickSort(object_t array[], int start_idx, int end_idx)
{
	object_t pivot_value;		//Creating variable, which contains pivot value
	int pivot_idx;				//Creating variable, which contains index of pivot
	int idx_tmp1, idx_tmp2;

	if(start_idx < end_idx)		//Check if there is sth to sort - length of array has to be greater then 0
	{
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

		//Recursive call QuickSort for left and right subarray
		QuickSort(array, start_idx, idx_tmp1 - 1);
		QuickSort(array, idx_tmp1 + 1, end_idx);
	}
}


#endif /* QUICKSORT_HPP_ */
