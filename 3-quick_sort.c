#include "sort.h"

void quick_sort(int *array, size_t size);
void value_switcher(int *_1st_num, int *_2nd_num);
int my_lomuto_partion(int *array, size_t size, int l, int r);
void my_lomuto_sort(int *array, size_t size, int l, int r);


/**
 * quick_sort - custom quick sort algorithm to
 *	sort an array of integers in ascending order
 * @array: array of integers
 * @size: array size
 *
 * Description: utilizes Lomuto partition scheme while printing after each swap
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}

	my_lomuto_sort(array, size, 0, size - 1);
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


/**
 * my_lomuto_partion - custom implementation of Lomuto partition scheme,
 *	which is used in the QuickSort algorithm to partition an
 *	array into two parts based on a switch_val element
 * @array: array of integers
 * @size: array size
 * @l: leftmost element index in the partition range
 * @r: rightmost element index in the partition range
 *
 * Return: index of final partition
 */
int my_lomuto_partion(int *array, size_t size, int l, int r)
{
	int index_above;
	int index_below;
	int *switch_val;

	/* selects the pivot value from the rightmost */
	/* element in the partition range */
	switch_val = array + r;

	for (index_above = index_below = l; index_below < r; index_below++)
	{
		i /* iterates through the array from the */
			/* leftmost index to the rightmost index */
		if (array[index_below] < *switch_val)
		{
			if (index_above < index_below)
			{
				value_switcher(array + index_below, array + index_above);
				print_array(array, size);
			}

			index_above++;
		}
	}

	if (array[index_above] > *switch_val)
	{
		value_switcher(array + index_above, switch_val);
		print_array(array, size);
	}

	return (index_above);
}

/**
 * my_lomuto_sort - local build of quicksort algorithm through recursion
 * @array: array of integers
 * @size: array size
 * @l: leftmost element index in the partition range
 * @r: rightmost element index in the partition range
 */
void my_lomuto_sort(int *array, size_t size, int l, int r)
{
	int pivot_idx;

	/* checks if the partition range is valid */
	if (r - l > 0)
	{
		pivot_idx = my_lomuto_partion(array, size, l, r);
		my_lomuto_sort(array, size, l, pivot_idx - 1);
		my_lomuto_sort(array, size, pivot_idx + 1, r);
	}
}
