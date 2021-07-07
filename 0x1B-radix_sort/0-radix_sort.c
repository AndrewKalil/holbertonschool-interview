#include "sort.h"

/**
 * max - Function that finds the maximum integer
 * @array: Array where the max number will be found
 * @size: Size of array
 * Return: Max Number
 */

int max(int *array, int size)
{
	int i;
	int maxint;

	for (maxint = array[0], i = 1; i < size; i++)
		maxint = (array[i] > maxint) ? array[i] : maxint;
	return (maxint);
}

/**
 * count - Function that sorts the array digit
 * @array: Array that will be sorted
 * @size: Size of array
 * @exp: Integer by which array[i] will be divided
 * Return: void function
 */
void count(int *array, int size, int exp)
{
	int i, *output, counter[10] = {0};

	output = malloc(sizeof(int) * size);
	if (!output)
		return;

	for (i = 0; i < size; i++)
		counter[(array[i] / exp) % 10]++;
	for (i = 1; i < 10; i++)
		counter[i] += counter[i - 1];
	for (i = size - 1; i >= 0; i--)
	{
		output[counter[(array[i] / exp) % 10] - 1] = array[i];
		counter[(array[i] / exp) % 10]--;
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];
	free(output);
}


/**
 * radix_sort - function that sorts an array of integers in ascending
 * order using the Radix sort algorithm
 * @array: Array to be sorted
 * @size: Size of array
 * Return: void function
 */
void radix_sort(int *array, size_t size)
{
	int maxint;
	int exp;

	if (size < 2)
		return;
	for (maxint = max(array, size), exp = 1; maxint / exp > 0; exp *= 10)
	{
		count(array, size, exp);
		print_array(array, size);
	}
}
