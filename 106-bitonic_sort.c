#include "sort.h"


void bitonic_sort(int *array, size_t size);
void merge_bitonic_sequence(int *array, size_t size, size_t startin_idx,
		size_t sub_size, char direction);
void RecursiveBitonicSort(int *array, size_t size, size_t startin_idx,
		size_t sub_size, char direction);
void value_switcher(int *_1st_num, int *_2nd_num);


/**
 * bitonic_sort - custom bitonic sort algorithm to sort an array of
 *		integers in ascending order
 * @array: array of integers
 * @size: array size
 *
 * Description: while printing iterates through the array until fully sorted
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}

	RecursiveBitonicSort(array, size, 0, size, UP);
}


/**
 * RecursiveBitonicSort - Perform a bitonic sequence operation
 *	on a subarray within the given array
 * @array: array of integers
 * @size: size of the array
 * @startin_idx: starting index of the subarray to be merged
 * @sub_size: size of the subarray to be merged
 * @direction: direction of the merge (UP or DOWN)
 */
void RecursiveBitonicSort(int *array, size_t size, size_t startin_idx,
		size_t sub_size, char direction)
{
	size_t split;
	char *string = (direction == UP) ? "UP" : "DOWN";

	split = sub_size / 2;

	if (sub_size > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", sub_size, size, string);
		print_array(array + startin_idx, sub_size);

		RecursiveBitonicSort(array, size, startin_idx, split, UP);
		RecursiveBitonicSort(array, size, startin_idx + split, split, DOWN);
		merge_bitonic_sequence(array, size, startin_idx, sub_size, direction);

		printf("Result [%lu/%lu] (%s):\n", sub_size, size, string);
		print_array(array + startin_idx, sub_size);
	}
}

/**
 * merge_bitonic_sequence - responsible for bitonic merge on a
 *	subarray within the given array
 * @array: array of integers
 * @size: size of the array
 * @startin_idx: starting index of the subarray to be merged
 * @sub_size: size of the subarray to be merged
 * @direction: flow direction of the merge (UP or DOWN)
 */
void merge_bitonic_sequence(int *array, size_t size, size_t startin_idx,
		size_t sub_size, char direction)
{
	size_t index;
	size_t step = sub_size / 2;

	if (sub_size > 1)
	{
		for (index = startin_idx; index < startin_idx + step; index++)
		{
			if ((direction == UP && array[index] > array[index + step]) ||
			    (direction == DOWN && array[index] < array[index + step]))
				value_switcher(array + index, array + index + step);
		}

		merge_bitonic_sequence(array, size, startin_idx, step, direction);
		merge_bitonic_sequence(array, size, startin_idx + step, step, direction);
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
