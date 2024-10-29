#include "sort.h"

void merge_subarr(int *subarr, int *buff, size_t front, size_t m,
		size_t back);
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * merge_subarr - Sort a subarray of integers.
 * @subarr: A subarray of an array of integers to sort.
 * @buff: A buffer to store the sorted subarray.
 * @front: The front index of the array.
 * @m: The middle index of the array.
 * @back: The back index of the array.
 */

void merge_subarr(int *subarr, int *buff, size_t front, size_t m,
		size_t back)
{
	size_t x, y, z = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, m - front);

	printf("[right]: ");
	print_array(subarr + m, back - m);

	for (x = front, y = m; x < m && y < back; z++)
		buff[z] = (subarr[x] < subarr[y]) ? subarr[x++] : subarr[y++];
	for (; x < m; x++)
		buff[z++] = subarr[x];
	for (; y < back; y++)
		buff[z++] = subarr[y];
	for (x = front, z = 0; x < back; x++)
		subarr[x] = buff[z++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 * merge_sort_recursive - Implement the merge sort algorithm through recursion.
 * @subarr: A subarray of an array of integers to sort.
 * @buff: A buffer to store the sorted result.
 * @front: The front index of the subarray.
 * @back: The back index of the subarray.
 */

void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back)
{
	size_t m;

	if (back - front > 1)
	{
		m = front + (back - front) / 2;
		merge_sort_recursive(subarr, buff, front, m);
		merge_sort_recursive(subarr, buff, m, back);
		merge_subarr(subarr, buff, front, m, back);
	}
}

/**
 * merge_sort - Sort an array of integers in ascending
 *              order using the merge sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * Description: Implements the top-down merge sort algorithm.
 */

void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	merge_sort_recursive(array, buff, 0, size);

	free(buff);
}

