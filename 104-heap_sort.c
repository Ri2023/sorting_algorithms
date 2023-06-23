#include "sort.h"

void heap_sort(int *array, size_t size);
void adjust_max_heap(int *array, size_t size, size_t baseIdx, size_t rootIdx);
void value_switcher(int *_1st_num, int *_2nd_num);


/**
 * heap_sort - custom heap sort algorithm to sort an
 *	array of integers in ascending order
 * @array: array of integers
 * @size: array size
 *
 * Description: while printing iterates through the array until fully sorted
 */
void heap_sort(int *array, size_t size)
{
	int index;

	if (array == NULL || size < 2)
	{
		return;
	}

	/* builds a max heap by calling the adjust_max_heap function */
	/* It starts from the parent of the last element and iterates */
	/* up to the root of the heap */
	for (index = (size / 2) - 1; index >= 0; index--)
	{
		adjust_max_heap(array, size, size, index);
	}

	for (index = size - 1; index > 0; index--)
	{
		value_switcher(array, array + index);
		print_array(array, size);
		adjust_max_heap(array, size, index, 0);
	}
}

/**
 * adjust_max_heap - Maintain the max heap property of a binary heap
 * @array: pointer to the array
 * @size: array size
 * @baseIdx: base index of the current sub-heap
 * @rootIdx: root index of the current sub-heap
 */
void adjust_max_heap(int *array, size_t size, size_t baseIdx, size_t rootIdx)
{
	size_t left_idx;
	size_t right_idx;
	size_t largest_idx;

	left_idx = 2 * rootIdx + 1;
	right_idx = 2 * rootIdx + 2;
	largest_idx = rootIdx;

	if (left_idx < baseIdx && array[left_idx] > array[largest_idx])
	{
		largest_idx = left_idx;
	}
	if (right_idx < baseIdx && array[right_idx] > array[largest_idx])
	{
		largest_idx = right_idx;
	}

	if (largest_idx != rootIdx)
	{
		value_switcher(array + rootIdx, array + largest_idx);
		print_array(array, size);
		adjust_max_heap(array, size, baseIdx, largest_idx);
	}
}

/**
 * value_switcher - takes two pointers to integers
 *	as input and swaps the values
 * @_1st_num: value of the first integer
 * @_2nd_num: value of the second integer
 */
void value_switcher(int *_1st_num, int *_2nd_num)
{
	int waiting_value;

	waiting_value = *_1st_num;
	*_1st_num = *_2nd_num;
	*_2nd_num = waiting_value;
}
