#ifndef INSERTSORT_HPP_
#define INSERTSORT_HPP_

template <typename object_t>
void InsertSort(object_t array[], int start_idx, int end_idx)
{
	int array_size = end_idx - start_idx;
	object_t element_tmp;
	int idx_tmp1, idx_tmp2;

	for(idx_tmp1 = 1; idx_tmp1 < array_size; idx_tmp1++)
	{
		element_tmp = array[idx_tmp1];
		idx_tmp2 = idx_tmp1;
		while( (idx_tmp2 > 0) && (element_tmp < array[idx_tmp2 - 1]) )
		{
			array[idx_tmp2] = array[idx_tmp2 - 1];
			idx_tmp2--;
		}
	}
}

#endif /* INSERTSORT_HPP_ */
