#include "sort.h"

/**
 * merge_compare - compares merges
 * @array: the integer array to sort
 * @start: the start index
 * @stop: the stop index
 * @new: the output array
 *
 * Return: void.
 */
void merge_compare(int *array, size_t start, size_t stop, int *new)
{
	size_t i = start, j, k, midle;

	j = midle = (start + stop) / 2;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + start, midle - start);
	printf("[right]: ");
	print_array(array + midle, stop - midle);
	for (k = start; k < stop; k++)
		if (i < midle && (j >= stop || array[i] <= array[j]))
		{
			new[k] = array[i++];
		}
		else
		{
			new[k] = array[j++];
		}
	printf("[Done]: ");
	print_array(new + start, stop - start);
}

/**
 * merge_sort_top_down - sorts top to down recursively
 * @array: the integer array to sort
 * @start: the start index
 * @stop: the stop index
 * @new: the output array
 *
 * Return: void.
 */
void merge_sort_top_down(int *array, size_t start, size_t stop, int *new)
{
	size_t midle;

	midle = (start + stop) / 2;
	if (stop - start < 2)
	{
		return;
	}
	merge_sort_top_down(new, start, midle, array);
	merge_sort_top_down(new, midle, stop, array);
	merge_compare(array, start, stop, new);
}


/**
 * merge_sort - sorts an array by merge sort algorithm
 * @array: the integer array to sort
 * @size: the size of the array
 *
 * Return: void.
 */
void merge_sort(int *array, size_t size)
{
	int *new_ar;
	size_t i;


	if (!array || size < 2)
		return;

	new_ar = malloc(sizeof(int) * size);
	if (!new_ar)
		return;
	for (i = 0; i < size; i++)
		new_ar[i] = array[i];
	merge_sort_top_down(new_ar, 0, size, array);
	free(new_ar);
}
