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
	}
	print_array((const int *)array, size);
}

/**
 * hoare_partition - partitions the array
 * @array: the integer array to sort
 * @size: the size of the array
 * @lo: the low index of the sort range
 * @hi: the high index of the sort range
 *
 * Return: void
 */
size_t hoare_partition(int *array, ssize_t size, ssize_t lo, ssize_t hi)
{
	ssize_t i = lo - 1, j = hi + 1;
	int pivot = array[hi];

	while (i < size)
	{
		while (array[++i] < pivot)
			;
		while (array[--j] > pivot)
			;
		if (i < j)
			swap(array, size, &array[i], &array[j]);
		else if (i >= j)
			break;
	}
	return (i);
}

/**
 * quicksort - quicksorts via hoare partitioning scheme
 * @array: the integer array to sort
 * @size: the size of the array
 * @lo: the low index of the sort range
 * @hi: the high index of the sort range
 *
 * Return: void
 */
void quicksort(int *array, size_t size, ssize_t lo, ssize_t hi)
{
	if (lo < hi)
	{
		size_t p = hoare_partition(array, size, lo, hi);

		quicksort(array, size, lo, p - 1);
		quicksort(array, size, p, hi);
	}
}

/**
 * quick_sort_hoare - calls quicksort
 * @array: the integer array to sort
 * @size: the size of the array
 *
 * Return: void
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quicksort(array, size, 0, size - 1);
}
