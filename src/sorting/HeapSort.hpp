#ifndef HEAPSORT_HPP_
#define HEAPSORT_HPP_

template <typename object_t>
static void hswap(object_t array[], int idx1, int idx2)		//Swapping two choosen elements of array
{
	object_t element_tmp = array[idx1];
	array[idx1] = array[idx2];
	array[idx2] = element_tmp;
}

template <typename object_t>
static void heapify(object_t array[], int heap_size, int parent_idx)
{
	int max_idx = parent_idx;					//Parent node idx
	int left_child_idx = 2 * parent_idx + 1;	//Left child node idx
	int right_child_idx = 2 * parent_idx + 2;	//Right child node idx

	if( (left_child_idx < heap_size) && (array[left_child_idx] > array[max_idx]) )
		max_idx = left_child_idx;

	if( (right_child_idx < heap_size) && (array[right_child_idx] > array[max_idx]) )
		max_idx = right_child_idx;

	if(max_idx != parent_idx)
	{
		hswap(array, max_idx, parent_idx);
		heapify(array, heap_size, max_idx);
	}
}

template <typename object_t>
void HeapSort(object_t array[], int start_idx, int end_idx)
{
	int array_size = end_idx - start_idx;
	int idx_tmp1;

	for(idx_tmp1 = array_size/2 - 1; idx_tmp1 >= 0; idx_tmp1--)
		heapify(array, array_size, idx_tmp1);

	for(idx_tmp1 = array_size - 1; idx_tmp1 >= 0; idx_tmp1--)
	{
		hswap(array, 0, idx_tmp1);
		heapify(array, --array_size, 0);
	}

}

#endif /* HEAPSORT_HPP_ */
