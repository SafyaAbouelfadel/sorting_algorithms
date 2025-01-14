#include "sort.h"
#define parent(x) (((x) - 1) / 2)
#define leftchild(x) (((x) * 2) + 1)

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
*sift_down - siftdown implementation
*
*@array: array to be sorted
*@start: start of array
*@end: end of array
*@size: size of array
*
*/
void sift_down(int *array, size_t start, size_t end, size_t size)
{
	size_t root = start, _swap, child;

	while (leftchild(root) <= end)
	{
		child = leftchild(root);
		_swap = root;
		if (array[_swap] < array[child])
			_swap = child;
		if (child + 1 <= end &&
			array[_swap] < array[child + 1])
			_swap = child + 1;
		if (_swap == root)
			return;
		swap(array, size, &array[root], &array[_swap]);
		root = _swap;
	}
}

/**
*heapify - makes heap in-place
*
*@array: array to be sorted
*@size: size of array
*
*/
void heapify(int *array, size_t size)
{
	ssize_t start;

	start = parent(size - 1);
	while (start >= 0)
	{
		sift_down(array, start, size - 1, size);
		start--;
	}
}
/**
*heap_sort - sort an array by heap sort algorithm
*
*@array: array to sort
*@size: size of array
*
*/
void heap_sort(int *array, size_t size)
{
	size_t end;

	if (!array || size < 2)
		return;
	heapify(array, size);
	end = size - 1;
	while (end > 0)
	{
		swap(array, size, &array[end], &array[0]);
		end--;
		sift_down(array, 0, end, size);
	}
}
