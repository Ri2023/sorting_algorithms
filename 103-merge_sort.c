#include "sort.h"

void merge_sort(int *array, size_t size);
void join_subarray(int *sbArr, int *buff_val, size_t frt_val,
		size_t mid, size_t bck_val);
void RecursiveMergeSort(int *sbArr, int *buff_val, size_t frt_val,
		size_t bck_val);


/**
 * merge_sort - custom merge sort algorithm to
 *	sort an array of integers in ascending order
 * @array: array of integers
 * @size: array size
 *
 * Description: while printing iterates through the array until fully sorted
 */
void merge_sort(int *array, size_t size)
{
	int *buffer_val;

	if (array == NULL || size < 2)
	{
		return;
	}

	buffer_val = malloc(sizeof(int) * size);

	if (buffer_val == NULL)
	{
		return;
	}

	/* alls a recursive helper function to perform the actual sorting */
	RecursiveMergeSort(array, buffer_val, 0, size);

	free(buffer_val);
}


/**
 * join_subarray - responsible for mergeing two
 *	subarrays into a single sorted subarray
 * @sbArr: original array pointer containing the subarrays
 * @buff_val: buffer array pointer for temporary storage
 * @frt_val: subarray first starting index
 * @mid_val: first subarray ending index and the second subarray starting index
 * @bck_val: second subarray ending index
 */
void join_subarray(int *sbArr, int *buff_val, size_t frt_val,
		size_t mid_val, size_t bck_val)
{
	size_t front_temp, mid_temp, x = 0;

	printf("Merging...\n[left]: ");
	print_array(sbArr + frt_val, mid_val - frt_val);

	printf("[right]: ");
	print_array(sbArr + mid_val, bck_val - mid_val);

	for (front_temp = frt_val, mid_temp = mid_val;
	front_temp < mid_val && mid_temp < bck_val; x++)
	{
		buff_val[x] = (sbArr[front_temp] < sbArr[mid_temp]) ?
		sbArr[front_temp++] : sbArr[mid_temp++];
	}
	for (; front_temp < mid_val; front_temp++)
	{
		buff_val[x++] = sbArr[front_temp];
	}
	for (; mid_temp < bck_val; mid_temp++)
	{
		buff_val[x++] = sbArr[mid_temp];
	}
	for (front_temp = frt_val, x = 0; front_temp < bck_val; front_temp++)
	{
		sbArr[front_temp] = buff_val[x++];
	}

	printf("[Done]: ");
	print_array(sbArr + frt_val, bck_val - frt_val);
}

/**
 * RecursiveMergeSort - a recursive implementation a merge sort algorithm
 * @sbArr: original array pointer containing the subarrays
 * @buff_val: buffer array pointer for temporary storage
 * @frt_val: subarray first starting index
 * @bck_val: second subarray ending index
 */
void RecursiveMergeSort(int *sbArr, int *buff_val, size_t frt_val,
		size_t bck_val)
{
	size_t midd_val;

	if (bck_val - frt_val > 1)
	{
		/* calculates the index value of the middle */
		/* element (valOfMid) within the subarray range */
		midd_val = frt_val + (bck_val - frt_val) / 2;

		/* ecursively calls itself to sort the left half of the subarray */
		RecursiveMergeSort(sbArr, buff_val, frt_val, midd_val);
		RecursiveMergeSort(sbArr, buff_val, midd_val, bck_val);

		/*  merge the two sorted halves into the original subarray */
		join_subarray(sbArr, buff_val, frt_val, midd_val, bck_val);
	}
}

