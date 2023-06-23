#include "sort.h"

void value_switcher(int *_1st_num, int *_2nd_num);


/**
 * bubble_sort - implements the bubble sort algorithm to
 *	sort an array of integers in ascending order
 * @array: integer array
 * @size: size of the array
 *
 * Description: prints and iterates until the array is sorted
 */
void bubble_sort(int *array, size_t size)
{
	size_t index;
	size_t array_len;
	bool sorted = false;

	if (array == NULL || size < 2)
	{
		return;
	}

	for (array_len = size; sorted == false; array_len--)
	{
		sorted = true;

		for (index = 0; index < array_len - 1; index++)
		{
			if (array[index] > array[index + 1])
			{
				value_switcher(array + index, array + index + 1);
				print_array(array, size);
				sorted = false;
			}
		}
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
