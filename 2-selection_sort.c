#include "sort.h"

void value_switcher(int *_1st_num, int *_2nd_num);


/**
 * selection_sort - custom selection sort algorithm to
 *	sort an array of integers in ascending order
 * @array: array of integers
 * @size: array size
 *
 * Description: while printing iterates through the array until fully sorted
 */
void selection_sort(int *array, size_t size)
{
	int *minimum_val;
	size_t a;
	size_t b;

	if (array == NULL || size < 2)
	{
		return;
	}

	for (a = 0; a < size - 1; a++)
	{
		minimum_val = array + a;
		for (b = a + 1; b < size; b++)
		{
			minimum_val = (array[b] < *minimum_val) ? (array + b) : minimum_val;
		}

		if ((array + a) != minimum_val)
		{
			value_switcher(array + a, minimum_val);
			print_array(array, size);
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
