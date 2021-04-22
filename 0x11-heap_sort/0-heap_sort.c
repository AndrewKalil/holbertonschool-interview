#include "sort.h"

/**
 * swap_array - swap between two position of an array
 * @array: array to swap
 * @first: first position
 * @last: last position
 * @size: size of the array
 */
void swap_array(int *array,  int first, int last, size_t size)
{
	int aux, value;

	value = array[first];
	aux = array[last];
	array[last] = value;
	array[first] = aux;
	print_array(array, size);
}

/**
 * bigger_heap - look for bigger in heap
 * @array: array of integers
 * @size_1: max index in binary tree
 * @idx: index of head node
 * @size_2: size of the array for printing
 */
void bigger_heap(int *array, size_t size_1, size_t idx, size_t size_2)
{
	size_t max, left, right;

	max = idx;
	left = 2 * idx + 1;
	right = 2 * idx + 2;

	if (left < size_1 && array[left] > array[max])
		max = left;

	if (right < size_1 && array[right] > array[max])
		max = right;

	if (max != idx)
	{
		swap_array(array, idx, max, size_2);

		bigger_heap(array, size_1, max, size_2);
	}
}

/**
 * heap_sort - sorts an array of integers in ascending order
 * @array: array of integers
 * @size: size of the array
 */
void heap_sort(int *array, size_t size)
{
	int i = 0;

	if (!array || size == 1)
		return;
	for (i = size / 2 - 1; i >= 0; i--)
		bigger_heap(array, size, i, size);

	for (i = size - 1; i > 0; i--)
	{
		swap_array(array, 0, i, size);
		bigger_heap(array, i, 0, size);
	}
}
