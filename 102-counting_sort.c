#include "sort.h"
/**
*integer_count- number of times integer appears in an array
*
*@array: the array to count
*@size: size of the array
*@range: number to check for occurance
*
*Return: number of occurances
*/
int integer_count(int *array, size_t size, int range)
{
	int count = 0;
	size_t i;

	for (i = 0; i < size; i++)
	{
		if (array[i] == range)
			count++;
	}
	return (count);
}

/**
*counting_sort - sorts an array using the Counting sort algorithm
*
*@array: array to be sorted
*@size: size of the array
*/
void counting_sort(int *array, size_t size)
{
	int j = 0, k = 0, m = 0;
	size_t b, c;
	int *array_2, *new_array;

	if (!array || size < 2)
		return;
	for (b = 0; b < size; b++)
	{
		if (array[b] > j)
		{
			j = array[b];
		}
	}
	array_2 = malloc(sizeof(int) * (j + 1));
	if (!array_2)
		return;
	for (c = 0; c < ((size_t)j + 1); c++)
	{
		if (c == 0)
			array_2[c] = integer_count(array, size, m);
		else
		{
			k = array_2[c - 1] + integer_count(array, size, m);
			array_2[c] = k;
		}
		m++;
	}
	print_array(array_2, (j + 1));
	new_array = malloc(sizeof(int) * size);
	if (!new_array)
	{
		free(array_2);
		return;
	}
	for (b = 0; b < size; b++)
		new_array[array_2[array[b]]-- - 1] = array[b];
	for (b = 0; b < size; b++)
		array[b] = new_array[b];
	free(new_array);
	free(array_2);
}
