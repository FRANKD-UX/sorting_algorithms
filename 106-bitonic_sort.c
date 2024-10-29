#include <stdio.h>
#include "sort.h"

/**
 * swap - Swap two integers in the array.
 * @array: The array where the elements are located.
 * @i: The first element index.
 * @j: The second element index.
 *
 * Return: void.
 */
void swap(int *array, int i, int j)
{
	int temp;

	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
	printf("Swap: %d <-> %d\n", array[i], array[j]);
}

/**
 * bitonic_merge - Merge two halves of the Bitonic sequence.
 * @array: The array to be sorted.
 * @low: The starting index.
 * @count: The number of elements to be sorted.
 * @dir: The direction of sorting (1 for ascending, 0 for descending).
 *
 * Return: void.
 */
void bitonic_merge(int *array, int low, int count, int dir)
{
	int k, i;

	if (count > 1)
	{
		k = count / 2;
		for (i = low; i < low + k; i++)
		{
			if (dir == (array[i] > array[i + k]))
				swap(array, i, i + k);
		}
		bitonic_merge(array, low, k, dir);
		bitonic_merge(array, low + k, k, dir);
	}
}

/**
 * bitonic_sort_recursive - Recursive helper function to perform Bitonic sort.
 * @array: The array to be sorted.
 * @low: The starting index.
 * @count: The number of elements to be sorted.
 * @dir: The direction of sorting (1 for ascending, 0 for descending).
 *
 * Return: void.
 */
void bitonic_sort_recursive(int *array, int low, int count, int dir)
{
	if (count > 1)
	{
		int k = count / 2;

		bitonic_sort_recursive(array, low, k, 1); /* Sort in ascending order */
		bitonic_sort_recursive(array, low + k, k, 0); /* Sort in descending order */
		bitonic_merge(array, low, count, dir);
	}
}

/**
 * bitonic_sort - Sort an array of integers in ascending order using
 * Bitonic sort.
 * @array: The array to be sorted.
 * @size: The number of elements in the array.
 *
 * Return: void.
 */
void bitonic_sort(int *array, size_t size)
{
	bitonic_sort_recursive(array, 0, size, 1);
}

