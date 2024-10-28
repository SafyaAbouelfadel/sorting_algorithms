#include "sort.h"

/**
 * get_max_gap - gets the a maximum Knuth Sequence gap for this size
 * @size: size of the array
 *
 * Return: the gap size
 */
size_t get_max_gap(size_t size)
{
	size_t g = 1;

	while (g < size)
		g = g * 3 + 1;
	return ((g - 1) / 3);
}

/**
 * shell_sort - Sorts an array of integers
 * @array: Pointer to the array to be sorted.
 * @size: Number of elements in the array.
 */
void shell_sort(int *array, size_t size)
{
	int tmp;
	size_t i, j, gap;

	if (!array || size < 2)
		return;

	for (gap = get_max_gap(size); gap; gap = (gap - 1) / 3)
	{
		for (i = gap; i < size; i++)
		{
			tmp = array[i];
			for (j = i; j > gap - 1 && array[j - gap] > tmp; j -= gap)
				array[j] = array[j - gap];
			array[j] = tmp;
		}
		print_array(array, size);
	}
}
