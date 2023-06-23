#include "sort.h"


void quick_sort_hoare(int *array, size_t size);
int custom_hoare_partition(int *array, size_t size, int l, int r);
void custom_hoare_sort(int *array, size_t size, int l, int r);
void value_switcher(int *_1st_num, int *_2nd_num);


/**
 * quick_sort_hoare - custom quick sort algorithm to
 *	sort an array of integers in ascending order
 * @array: array of integers
 * @size: array size
 *
 * Description: while printing iterates through the array until fully sorted
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}

	custom_hoare_sort(array, size, 0, size - 1);
}

/**
 * custom_hoare_partition - implements the Hoare partition
 *	scheme on a subarray within the given array
 * @array: array of integers
 * @size: array size
 * @l: subarray left index
 * @r: subarray right index
 *
 * Return: final partition index
 */
int custom_hoare_partition(int *array, size_t size, int l, int r)
{
	int pivot_val;
	int val_above;
	int val_below;

	pivot_val = array[r];
	for (val_above = l - 1, val_below = r + 1; val_above < val_below;)
	{
		do {
			val_above++;
		} while (array[val_above] < pivot_val);

		do {
			val_below--;
		} while (array[val_below] > pivot_val);

		if (val_above < val_below)
		{
			value_switcher(array + val_above, array + val_below);
			print_array(array, size);
		}
	}

	return (val_above);
}

/**
 * custom_hoare_sort - implements the Hoare sort algorithm
 *	on a subarray within the given array
 * @array: array of integers
 * @size: array size
 * @l: subarray left index
 * @r: subarray right index
 */
void custom_hoare_sort(int *array, size_t size, int l, int r)
{
	int pivot;

	if (r - l > 0)
	{
		pivot = custom_hoare_partition(array, size, l, r);
		custom_hoare_sort(array, size, l, pivot - 1);
		custom_hoare_sort(array, size, pivot, r);
	}
}

/**
 * value_switcher - takes two pointers to
 *	integers as input and swaps the values
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
