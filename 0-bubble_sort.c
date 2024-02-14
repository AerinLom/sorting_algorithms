#include "sort.h"

/**
  *swap - swaps values in array
  *@val_1: first value
  *@val_2: second value
  */

void swap(int *val_1, int *val_2)
{
	int swap_val = *val_1;
	*val_1 = *val_2;
	*val_2 = swap_val;
}

/**
 *bubble_sort - bubble sorts an array of integers in ascending order
 *@array: array of integers
 *@size: size of array of integers
 */

void bubble_sort(int *array, size_t size)
{
	int swap_flag;
	size_t iteration, index;

	if (array == NULL || size < 2)
	{
		return;
	}

	for (iteration = 0; iteration < size - 1; iteration++)
	{
		swap_flag = 0;
		for (index = 0; index < size - iteration - 1; index++)
		{
			if (array[index] > array[index + 1])
			{
				swap(&array[index], &array[index + 1]);
				print_array(array, size);
				swap_flag = 1;
			}
		}
		if (!swap_flag)
		{
			break;
		}
	}
}
