#ifndef BUBBLESORT_HPP_
#define BUBBLESORT_HPP_

template <typename object_t>
static void bswap(object_t array[], int idx1, int idx2)		//Swapping two choosen elements of array
{
	object_t element_tmp = array[idx1];
	array[idx1] = array[idx2];
	array[idx2] = element_tmp;
}

template <typename object_t>
void BubbleSort(object_t array[], int start_idx, int end_idx)
{
	int array_size;
	int idx_tmp;
	bool swap_flag;
	array_size = end_idx - start_idx;

	do
	{
		swap_flag = false;
		for(idx_tmp = 0; idx_tmp < array_size; idx_tmp++ )
		{
			if( array[idx_tmp] > array[idx_tmp +1] )			//Jeœli poprzedni element jest wiêkszy od nastêpnego
			{
				bswap(array, idx_tmp, idx_tmp+1);															//Nastêpujê zamiana miejscami
				swap_flag = true;																		//Ustawienie flagi informuj¹cej o zamianie elementów miejscami
			}
		}
	}
	while(swap_flag);
}

#endif /* BUBBLESORT_HPP_ */
