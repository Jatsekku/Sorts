#ifndef MERGESORT_HPP_
#define MERGESORT_HPP_

template <typename object_t>
void MergeSort(object_t array[], int start_idx, int end_idx)
{
	int left_idx, sym_idx, right_idx;
	int idx_tmp1, idx_tmp2, idx_tmp3;

	sym_idx = (start_idx + end_idx) / 2;

	if(start_idx != end_idx)
	{
		MergeSort(array, start_idx, sym_idx);
		MergeSort(array, sym_idx+1, end_idx);

		object_t* array_tmp = new object_t[end_idx - start_idx +1];
		idx_tmp1 = 0;
		left_idx = start_idx;
		right_idx = sym_idx+1;

		while(left_idx <= sym_idx && right_idx <= end_idx)
		{
			if(array[left_idx] < array[right_idx])
				array_tmp[idx_tmp1] = array[left_idx++];
			else
				array_tmp[idx_tmp1] = array[right_idx++];
			idx_tmp1++;
		}

		while(left_idx <= sym_idx)
			array_tmp[idx_tmp1++] = array[left_idx++];

		while(right_idx <= end_idx)
			array_tmp[idx_tmp1++] = array[right_idx++];

		for(idx_tmp2 = start_idx, idx_tmp3 = 0; idx_tmp2 <= end_idx; idx_tmp2++, idx_tmp3++)
			array[idx_tmp2] = array_tmp[idx_tmp3];
		delete array_tmp;												//Zwolnienie pamiêci
	}
}

#endif /* MERGESORT_HPP_ */
