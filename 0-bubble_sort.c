#include "sort.h"
#include <stdio.h>

/**
 * bubble_sort - Sorts an array of int in ascending order using Bubble sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void bubble_sort(int *array, size_t size)
{
	int swapped, temp;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swapped = 1;

				/* Print the array after each swap */
				for (size_t k = 0; k < size; k++)
				{
					printf("%d", array[k]);
					if (k < size - 1)
						printf(", ");
				}

				printf("\n");
			}
		}
		if (swapped == 0)
			break;
	}
}
