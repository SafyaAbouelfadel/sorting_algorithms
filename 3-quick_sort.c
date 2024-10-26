#include "sort.h"

/**
 * swap - swaps 2 int values
 * @array: the integer array to sort
 * @size: the size of the array
 * @first: address of first value
 * @second: address of second value
 *
 * Return: void
 */
void swap(int *array, size_t size, int *first, int *second)
{
	if (*first != *second)
	{
		*first = *first + *second;
		*second = *first - *second;
		*first = *first - *second;
		print_array((const int *)array, size);
	}
}

/**
 * lomuto_parti - partitions the array
 * @array: the integer array to sort
 * @size: the size of the array
 * @lo: the low index of the sort range
 * @hi: the high index of the sort range
 *
 * Return: size_t
 */
size_t lomuto_parti(int *array, size_t size, ssize_t lo, ssize_t hi)
{
	int k, m, pivot = array[hi];

	for (k = m = lo; m < hi; m++)
		if (array[m] < pivot)
			swap(array, size, &array[m], &array[k++]);
	swap(array, size, &array[k], &array[hi]);

	return (k);
}

/**
 * quick_so - quicksorts via Lomuto partitioning scheme
 * @array: the integer array to sort
 * @size: the size of the array
 * @lo: the low index of the sort range
 * @hi: the high index of the sort range
 *
 * Return: void
 */
void quick_so(int *array, size_t size, ssize_t lo, ssize_t hi)
{
	if (lo < hi)
	{
		size_t pv = lomuto_parti(array, size, lo, hi);

		quick_so(array, size, lo, pv - 1);
		quick_so(array, size, pv + 1, hi);
	}
}

/**
 * quick_sort - calls quicksort
 * @array: the integer array to sort
 * @size: the size of the array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;
	quick_so(array, size, 0, size - 1);
}
