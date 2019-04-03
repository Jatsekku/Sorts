#include <iostream>
#include <time.h>
#include <string.h>
#include <windows.h>
#include <fstream>
#include "sorting/MergeSort.hpp"
#include "sorting/QuickSort.hpp"
#include "sorting/IntroSort.hpp"
#include "sorting/BubbleSort.hpp"
#include "sorting/HeapSort.hpp"
#include "sorting/InsertSort.hpp"

//enum types
enum array_size_t{_10k = 10000, _50k = 50000, _100k = 100000, _500k = 500000, _1M = 1000000};

enum array_type_t{_0p = 0, _25p = 250, _50p = 500, _75p = 750, _95p = 950, _99p = 990, _997p = 997, _rev = -1};

enum sort_type_t{bubble = 0, insert = 1, heap = 2, merge = 3, quick = 4, intro = 5, shell = 6};

//sorting functions
void GeneralSort(int sort_type, int array[], int start_idx, int end_idx)
{
	switch(sort_type)
	{
		case bubble:
		{
			BubbleSort<int>(array, start_idx, end_idx);
		}
		break;

		case insert:
		{
			InsertSort<int>(array, start_idx, end_idx);
		}
		break;

		case heap:
		{
			HeapSort<int>(array, start_idx, end_idx);
		}
		break;

		case merge:
		{
			MergeSort<int>(array, start_idx, end_idx);
		}
		break;

		case quick:
		{
			QuickSort<int>(array, start_idx, end_idx);
		}
		break;

		case intro:
		{
			IntroSort<int>(array, start_idx, end_idx);
		}
		break;

		case shell:
		{
			//ShellSort<int>(array, start_idx, end_idx);
		}
		break;
	}

}

double GeneralSort_Measure(int sort_type, int array[], int start_idx, int end_idx)
{
	clock_t start, stop;

	switch(sort_type)
	{
		case bubble:
		{
			start = clock();
			BubbleSort<int>(array, start_idx, end_idx);
			stop = clock();
		}
		break;

		case insert:
		{
			start = clock();
			InsertSort<int>(array, start_idx, end_idx);
			stop = clock();
		}
		break;

		case heap:
		{
			start = clock();
			HeapSort<int>(array, start_idx, end_idx);
			stop = clock();
		}
		break;

		case merge:
		{
			start = clock();
			MergeSort<int>(array, start_idx, end_idx);
			stop = clock();
		}
		break;

		case quick:
		{
			start = clock();
			QuickSort<int>(array, start_idx, end_idx);
			stop = clock();
		}
		break;

		case intro:
		{
			start = clock();
			IntroSort<int>(array, start_idx, end_idx);
			stop = clock();
		}
		break;

		case shell:
		{
			start = clock();
			//ShellSort<int>(array, start_idx, end_idx);
			stop = clock();
		}
		break;
	}
	return (double)(stop-start) / CLOCKS_PER_SEC;
}

//Array functions
void Array_Generate(int array[], int array_size, int _array_type)
{
	int idx_tmp1, idx_tmp2;

	if(_array_type == -1)
	{
		for(idx_tmp1 = 0; idx_tmp1 < array_size; idx_tmp1++)
			array[idx_tmp1] = array_size - idx_tmp1;
	}
	else
	{
		double array_type = (double)(_array_type/1000);
		int limit = (array_type * array_size);
		for(idx_tmp1 = 0; idx_tmp1 < limit; idx_tmp1++)
			array[idx_tmp1] = idx_tmp1;
		for(idx_tmp2 = limit; idx_tmp2 < array_size; idx_tmp2++)
			array[idx_tmp2] = rand();
	}
}

void Array_Print(int array[], array_size_t _array_size)
{
	int idx_tmp1;
	int array_size = (int)_array_size;
	for(idx_tmp1 = 0; idx_tmp1  < array_size; idx_tmp1++)
		std::cout << array[idx_tmp1] << std::endl;
}

int Array_Check(int array[], int array_size)
{
	int idx_tmp1;
	int ok_cnt = 0;

	for(idx_tmp1 = 0; idx_tmp1 < array_size; idx_tmp1++)
	{
		if(array[idx_tmp1] <= array[idx_tmp1 + 1])
			ok_cnt++;
	}

	return ok_cnt;
}

//Enum -> String translation functions
std::string SortType2String(int sort_type)
{
	switch(sort_type)
	{
		case bubble:
		{
			return "BubbleSort";
		}
		break;

		case insert:
		{
			return "InsertSort";
		}
		break;

		case heap:
		{
			return "HeapSort";
		}
		break;

		case merge:
		{
			return "MergeSort";
		}
		break;

		case quick:
		{
			return "QuickSort";
		}
		break;

		case intro:
		{
			return "IntroSort";
		}
		break;

		case shell:
		{
			return "ShellSort";
		}
		break;
	}

	return "Invalid sort type";
}

std::string ArrayType2String(int array_type)
{
	switch(array_type)
	{
		case _0p:
		{
			return "0%";
		}
		break;

		case _25p:
		{
			return "25%";
		}
		break;

		case _50p:
		{
			return "50%";
		}
		break;

		case _75p:
		{
			return "75%";
		}
		break;

		case _95p:
		{
			return "95%";
		}
		break;

		case _99p:
		{
			return "99%";
		}
		break;

		case _997p:
		{
			return "99,7%";
		}
		break;

		case _rev:
		{
			return "reversed";
		}
		break;
	}
	return "Invalid array type";

}

std::string ArraySize2String(int array_size)
{
	switch(array_size)
	{
		case _10k:
		{
			return "10 000";
		}
		break;

		case _50k:
		{
			return "50 000";
		}
		break;

		case _100k:
		{
			return "100 000";
		}
		break;

		case _500k:
		{
			return "500 000";
		}
		break;

		case _1M:
		{
			return "1 000 000";
		}
		break;
	}
	return "Invalid array size";
}

//Debug & measurements functions
void AllSort_Check(int tab_tmp[])
{
	int array_size[] = {_10k, _50k, _100k, _500k, _1M};
	int array_type[] = {_0p, _25p, _50p, _75p, _95p, _99p, _997p, _rev};
	int sort_type[] =  {intro, merge, quick};

	int array_size_idx;
	int array_type_idx;
	int sort_type_idx;

	int sorted_result;
	HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);



	for(sort_type_idx = 0; sort_type_idx < 3; sort_type_idx++)
	{
		std::cout << "__________________________________________________________________________________" << std::endl;
		std::cout << "Testing sorting algorithm: " << SortType2String(sort_type[sort_type_idx]) << std::endl;

		for(array_type_idx = 0; array_type_idx < 8; array_type_idx++)
		{
			std::cout << "Array Type: " << ArrayType2String(array_type[array_type_idx]) << std::endl;
			for(array_size_idx = 0; array_size_idx < 5; array_size_idx++)
			{
				std::cout << "Array Size: " << ArraySize2String(array_size[array_size_idx]) << std::endl;

				Array_Generate(tab_tmp, array_size[array_size_idx], array_type[array_type_idx]);
				GeneralSort(sort_type[sort_type_idx],tab_tmp, 0, array_size[array_size_idx]);
				sorted_result = Array_Check(tab_tmp, array_size[array_size_idx]);
				std::cout << "Sorted: " << sorted_result << " elements" << std::endl;
				if(sorted_result == array_size[array_size_idx])
				{
					SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
					std::cout << "OK!" << std::endl;
				}
				else
				{
					SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
					std::cout << "FAIL!" << std::endl;
				}
				SetConsoleTextAttribute( hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
			}
		}
	}
}


void AllSort_Measure(int tab_tmp[], char* path)
{
	int array_size[] = {_10k, _50k, _100k, _500k, _1M};
	int array_type[] = {_0p, _25p, _50p, _75p, _95p, _99p, _997p, _rev};
	int sort_type[] =  {intro, merge, quick};

	int array_size_idx;
	int array_type_idx;
	int sort_type_idx;
	int idx_tmp;
	long progress_cnt;
	long all_loops_factor = (3*8*5*100)/100;
	double time_result;
	double min_value = 100, max_value = 0, av_value, av_sum;

	std::fstream file;
	file.open(path, std::ios::out);



	std::cout << "Progress bar:" << std::endl
	<< "0%----------------------------------------------------------------------------------------------100%" << std::endl;

	for(sort_type_idx = 0; sort_type_idx < 3; sort_type_idx++)
	{
		file << "__________________________________________________________________________________" << std::endl;
		file << "Testing sorting algorithm: " << SortType2String(sort_type[sort_type_idx]) << std::endl;

		for(array_type_idx = 0; array_type_idx < 8; array_type_idx++)
		{
			file << "Array Type: " << ArrayType2String(array_type[array_type_idx]) << std::endl;
			for(array_size_idx = 0; array_size_idx < 5; array_size_idx++)
			{
				file << "Array Size: " << ArraySize2String(array_size[array_size_idx]) << std::endl;
				for(idx_tmp = 0; idx_tmp < 100; idx_tmp++)
				{
					Array_Generate(tab_tmp, array_size[array_size_idx], array_type[array_type_idx]);
					time_result = GeneralSort_Measure(sort_type[sort_type_idx], tab_tmp, 0, array_size[array_size_idx]);
					if(time_result < min_value) min_value = time_result;
					if(time_result > max_value) max_value = time_result;
					av_sum += time_result;
					//file << time_result << std::endl;
					progress_cnt++;
					if(!(progress_cnt%all_loops_factor))
						std::cout << (char)219;
				}
				av_value = av_sum/100;
				file << "!!!DANE!!!: " << std::endl;
				file << "min_value = " << min_value << std::endl;
				file << "max_value = " << max_value << std::endl;
				file << "av_value = " << av_value << std::endl;
				av_value = 0;
				av_sum = 0;
				max_value = 0;
				min_value = 100;
			}
		}
	}
}


int main(int argc, char* argv[])
{

	int *tab_tmp = new int[_1M];
	AllSort_Check(tab_tmp);
	AllSort_Measure(tab_tmp, argv[1]);



}

