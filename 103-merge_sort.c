#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * merge - Merges two sorted subarrays into a single sorted array.
 * @array: The main array to sort.
 * @temp: Temporary array used for merging.
 * @left: Starting index of the left subarray.
 * @mid: Middle index where the array is divided.
 * @right: Ending index of the right subarray.
 */
void merge(int *array, int *temp, size_t left, size_t mid, size_t right)
{
	size_t i = left, j = mid, k = left;

	printf("Merging...\n");
	printf("[left]: ");
	for (size_t x = left; x < mid; x++)
		printf("%d%s", array[x], x < mid - 1 ? ", " : "");
	printf("\n[right]: ");
	for (size_t y = mid; y < right; y++)
		printf("%d%s", array[y], y < right - 1 ? ", " : "");
	printf("\n");

	while (i < mid && j < right)
	{
		if (array[i] <= array[j])
			temp[k++] = array[i++];
		else
			temp[k++] = array[j++];
	}
	while (i < mid)
		temp[k++] = array[i++];
	while (j < right)
		temp[k++] = array[j++];

	for (k = left; k < right; k++)
		array[k] = temp[k];

	printf("[Done]: ");
	for (size_t z = left; z < right; z++)
		printf("%d%s", array[z], z < right - 1 ? ", " : "");
	printf("\n");
}

/**
 * merge_sort_recursive - Recursively divides and sorts the array.
 * @array: The array to sort.
 * @temp: Temporary array for merging.
 * @left: Starting index of the subarray.
 * @right: Ending index of the subarray.
 */
void merge_sort_recursive(int *array, int *temp, size_t left, size_t right)
{
	if (right - left > 1)
	{
		size_t mid = left + (right - left) / 2;

		merge_sort_recursive(array, temp, left, mid);
		merge_sort_recursive(array, temp, mid, right);
		merge(array, temp, left, mid, right);
	}
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 *              using the Merge Sort algorithm.
 * @array: The array to sort.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (array == NULL || size < 2)
		return;

	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;

	merge_sort_recursive(array, temp, 0, size);
	free(temp);
}

