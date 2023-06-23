#include "sort.h"

void radix_sort(int *array, size_t size);
int locateMax(int *array, int size);
void my_radix_sort(int *array, size_t size, int significance, int *tmp);



/**
 * radix_sort - custom radix sort algorithm to sort an
 *	array of integers in ascending order
 * @array: array of integers
 * @size: array size
 *
 * Description: while printing iterates through the array until fully sorted
 */
void radix_sort(int *array, size_t size)
{
	int maximum;
	int checkSignificance;
	int *temp;

	if (array == NULL || size < 2)
	{
		return;
	}

	temp = malloc(sizeof(int) * size);

	if (temp == NULL)
	{
		return;
	}

	maximum = locateMax(array, size);

	for (checkSignificance = 1; maximum / checkSignificance > 0;
	checkSignificance *= 10)
	{
		my_radix_sort(array, size, checkSignificance, temp);
		print_array(array, size);
	}

	free(temp);
}


/**
 * locateMax - locates maximum value in an array of integers
 * @array: array of integers
 * @size: array size
 *
 * Return: maximum integer in an array
 */
int locateMax(int *array, int size)
{
	int max_val;
	int index;

	for (max_val = array[0], index = 1; index < size; index++)
	{
		if (array[index] > max_val)
			max_val = array[index];
	}

	return (max_val);
}

/**
 * my_radix_sort - custom radix counting sort algorithm
 * @array: integers array
 * @size: array size
 * @significance: significance of the current digit being sorted
 * @tmp: temp array
 */
void my_radix_sort(int *array, size_t size, int significance, int *tmp)
{
	size_t index;
	int frequency[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	for (index = 0; index < size; index++)
	{
		frequency[(array[index] / significance) % 10] += 1;
	}

	for (index = 0; index < 10; index++)
	{
		frequency[index] += frequency[index - 1];
	}

	for (index = size - 1; (int)index >= 0; index--)
	{
		tmp[frequency[(array[index] / significance) % 10] - 1] = array[index];
		frequency[(array[index] / significance) % 10] -= 1;
	}

	for (index = 0; index < size; index++)
	{
		array[index] = tmp[index];
	}
}

