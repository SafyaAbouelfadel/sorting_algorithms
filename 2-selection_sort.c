#include "sort.h"
/**
 *selection_sort- function that sorts using selection sort algorithm
 *
 *@array: array to be sorted
 *@size: size of the array
 *
 */
void selection_sort(int *array, size_t size)
{
	size_t min_pos, j, k;
	int temp;

	if (!array || size < 2)
		return;

	for (j = 0; j < size - 1; j++)
	{
		min_pos = j;
		for (k = j + 1; k < size; k++)
		{
		if (array[k] < array[min_pos])
			min_pos = k;
		}
		if (min_pos != j)
		{
		temp = array[j];
		array[j] = array[min_pos];
		array[min_pos] = temp;
		print_array(array, size);
		}
	}
