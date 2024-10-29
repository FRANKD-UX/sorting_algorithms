#include "sort.h"

/**
 * counting_sort - Sort an array using the counting sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void counting_sort(int *array, size_t size)
{
	int max, i;
	int *count, *output;

	if (size < 2)
		return;

	/* Find the maximum value in the array */
	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	/* Allocate memory for count and output arrays */
	count = malloc((max + 1) * sizeof(int));
	output = malloc(size * sizeof(int));
	if (count == NULL || output == NULL)
	{
		free(count);
		free(output);
		return;
	}

	/* Initialize count array */
	for (i = 0; i <= max; i++)
		count[i] = 0;

	/* Store the count of each element */
	for (i = 0; i < size; i++)
		count[array[i]]++;

	/* Change count[i] so that count[i] contains the
	 * actual position of this element in output array */
	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];

	/* Build the output array */
	for (i = size - 1; i >= 0; i--)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}

	/* Copy the output array to array */
	for (i = 0; i < size; i++)
		array[i] = output[i];

	/* Free allocated memory */
	free(count);
	free(output);
}

