#include "sort.h"

/**
 * get_digit - gets a digit from a number
 * @number: the integer
 * @digit: the digit position to get
 *
 * Return: the digit value at given position
**/
int get_digit(long number, int digit)
{
	long i = 0L, pow = 1L, result;

	for (i = 0; i < digit; i++)
		pow *= 10L;
	result = ((number / pow) % 10);
	return (result);
}

/**
 * radix_pass - sorts by radix
 * @array: the integer array to sort
 * @size: the size of the array
 * @digit: the current digit to check
 * @new_array: target array of same size
 *
 * Return: void.
 */
int radix_pass(int *array, ssize_t size, int digit, int *new_array)
{
	ssize_t i;
	int buckts[10] = {0};

	for (i = 0; i < size; i++)
		buckts[get_digit(array[i], digit)]++;
	for (i = 1; i <= 9; i++)
		buckts[i] += buckts[i - 1];
	for (i = size - 1; i > -1; i--)
		new_array[buckts[get_digit(array[i], digit)]-- - 1] = array[i];
	return (1);
}

/**
 * radix_sort - sorts an array by radix algorithm
 * @size: the size of the array
 * @array: the integer array to sort
 *
 * Return: the gap size
 */
void radix_sort(int *array, size_t size)
{
	int *old, *new, *tmp_ptr, *ptr, max = 0;
	size_t i, sd = 1;

	if (!array || size < 2)
		return;

	for (i = 0; i < size; i++)
		if (array[i] > max)
			max = array[i];
	while (max /= 10)
		sd++;
	old = array;
	new = ptr = malloc(sizeof(int) * size);
	if (!new)
		return;
	for (i = 0; i < sd; i++)
	{
		radix_pass(old, (ssize_t)size, i, new);
		tmp_ptr = old;
		old = new;
		new = tmp_ptr;
		print_array(old, size);
	}
	for (i = 0; i < size; i++)
		array[i] = old[i];
	free(ptr);
}
