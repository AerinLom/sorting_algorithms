#include "sort.h"

/**
 * selection_sort - takes an array of numbers and sorts in ascending order
 * @array: An array of numbers
 * @size: byte size of array
 */
void selection_sort(int *array, size_t size)
{
	size_t a, b;

	if (array == NULL || size < 2)
		return;

	for (a = 0; a < size - 1; a++)
	{
		size_t smallest = a;

		for (b = a + 1; b < size; b++)
		{
			if (array[b] < array[smallest])
				smallest = b;
		}

		if (smallest != a)
		{
			int t = array[a];

			array[a] = array[smallest];
			array[smallest] = t;
			print_array(array, size);
		}
	}
}

/**
 * exchange_numbers - takes two values and swaps them
 * @num_1: first number to swap
 * @num_2: second number to swap
 */
void exchange_numbers(int *num_1, int *num_2)
{
	int num_ptr;

	num_ptr = *num_1;
	*num_1 = *num_2;
	*num_2 = num_ptr;
}

