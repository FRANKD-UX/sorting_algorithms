#include "sort.h"

/**
 * swap - Swaps two integers in an array.
 * @a: First integer to swap.
 * @b: Second integer to swap.
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * sift_down - Fixes a heap by moving the root element down.
 * @array: Array to be sorted.
 * @start: Starting index of the heap.
 * @end: Ending index of the heap.
 * @size: Size of the array.
 */
void sift_down(int *array, size_t start, size_t end, size_t size)
{
	size_t root = start;
	size_t child, swap_idx;

	while ((root * 2 + 1) <= end)
	{
		child = root * 2 + 1;
		swap_idx = root;

		if (array[swap_idx] < array[child])
			swap_idx = child;

		if ((child + 1 <= end) && (array[swap_idx] < array[child + 1]))
			swap_idx = child + 1;

		if (swap_idx == root)
			return;

		swap(&array[root], &array[swap_idx]);
		print_array(array, size);
		root = swap_idx;
	}
}

/**
 * heapify - Builds the heap from the array.
 * @array: Array to turn into a heap.
 * @size: Size of the array.
 */
void heapify(int *array, size_t size)
{
	ssize_t start = (size - 2) / 2;

	while (start >= 0)
	{
		sift_down(array, start, size - 1, size);
		start--;
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap sort.
 * @array: Array to be sorted.
 * @size: Size of the array.
 */
void heap_sort(int *array, size_t size)
{
	size_t end;

	if (array == NULL || size < 2)
		return;

	heapify(array, size);
	end = size - 1;
	while (end > 0)
	{
		swap(&array[end], &array[0]);
		print_array(array, size);
		end--;
		sift_down(array, 0, end, size);
	}
}

