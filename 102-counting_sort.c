#include "sort.h"

int locateMax(int *array, int size);

/**
 * counting_sort - custom counting sort algorithm to
 *	sort a doubly-linked list in ascending order
 * @array: array of integers
 * @size: array size
 *
 * Description: while printing iterates through the array until fully sorted
 */
void counting_sort(int *array, size_t size)
{
	int *sorted_arr, max_val, *count_arr, index;

	if (array == NULL || size < 2)
		return;

	sorted_arr = malloc(sizeof(int) * size);
	if (sorted_arr == NULL)
		return;
	max_val = locateMax(array, size);
	count_arr = malloc(sizeof(int) * (max_val + 1));
	if (count_arr == NULL)
	{
		free(sorted_arr);
		return;
	}

	for (index = 0; index < (max_val + 1); index++)
		count_arr[index] = 0;
	for (index = 0; index < (int)size; index++)
		count_arr[array[index]] += 1;
	for (index = 0; index < (max_val + 1); index++)
		count_arr[index] += count_arr[index - 1];
	print_array(count_arr, max_val + 1);

	for (index = 0; index < (int)size; index++)
	{
		sorted_arr[count_arr[array[index]] - 1] = array[index];
		count_arr[array[index]] -= 1;
	}

	for (index = 0; index < (int)size; index++)
		array[index] = sorted_arr[index];

	free(sorted_arr);
	free(count_arr);
}


/**
 * locateMax - searches for the maximum value in an array of integers
 * @array: array of integers
 * @size: array size
 *
 * Return: value of maximum integer in the array
 */
int locateMax(int *array, int size)
{

	int max_val;
	int index;

	for (max_val = array[0], index = 1; index < size; index++)
	{
		/* each element, if it is greater than the current maximum value */
		/* the maximum value is updated to the new element */
		if (array[index] > max_val)
			max_val = array[index];
	}

	return (max_val);
}
