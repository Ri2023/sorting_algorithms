#include "sort.h"

void value_switcher(int *_1st_num, int *_2nd_num);

/**
 * shell_sort - custom shell sort algorithm to sort
 *	an array of integers in ascending order
 * @array: array of integers
 * @size: array size
 *
 * Description: while printing iterates through the array until fully sorted
 */
void shell_sort(int *array, size_t size)
{
	size_t a;
	size_t b;
	size_t space;

	if (array == NULL || size < 2)
	{
		return;
	}

	/* etermines the initial gap value (space) for the Shell sort */
	/* It uses the Knuth sequence formula (space = space * 3 + 1) to */
	/* calculate the largest gap value that is less than the array size */
	for (space = 1; space < (size / 3);)
	{
		space = space * 3 + 1;
	}

	for (; space >= 1; space /= 3)
	{
		for (a = space; a < size; a++)
		{
			b = a;
			while (b >= space && array[b - space] > array[b])
			{
				value_switcher(array + b, array + (b - space));
				b -= space;
			}
		}
		print_array(array, size);
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
