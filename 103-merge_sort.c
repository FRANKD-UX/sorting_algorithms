#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge - Merges two sorted subarrays into a single sorted array.
 * @array: The main array containing the subarrays to merge.
 * @left: The starting index of the left subarray.
 * @mid: The ending index of the left subarray and starting of right.
 * @right: The ending index of the right subarray.
 * @temp: Temporary array to store the merged output.
 */
void merge(int *array, int left, int mid, int right, int *temp)
{
	int i = left, j = mid, k = 0;

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

	for (i = left, k = 0; i < right; i++, k++)
		array[i] = temp[k];
}

/**
 * top_down_split_merge - Recursively splits and merges subarrays.
 * @array: The array to be sorted.
 * @left: The starting index of the current subarray.
 * @right: The ending index of the current subarray.
 * @temp: Temporary array to store intermediate merged results.
 */
void top_down_split_merge(int *array, int left, int right, int *temp)
{
	int mid;

	if (right - left <= 1)
		return;

	mid = (left + right) / 2;

	top_down_split_merge(array, left, mid, temp);
	top_down_split_merge(array, mid, right, temp);
	merge(array, left, mid, right, temp);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using
 *              the Merge Sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (size < 2)
		return;

	temp = malloc(size * sizeof(int));
	if (!temp)
		return;

	top_down_split_merge(array, 0, size, temp);
	free(temp);
}

