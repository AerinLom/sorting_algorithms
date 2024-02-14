#include "sort.h"
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
/**
 * selection_sort - takes an array of numbers and sorts in ascending order
 * @array: An array of numbers
 * @size: byte size of array
 */
void selection_sort(int *array, size_t size)
{
	int *smallest;
	size_t a, b;

	if (array == NULL || size < 2)
		return;

	for (a = 0; a < size - 1; a++)
	{
		smallest = array + a;
		for (b = a + 1; b < size; b++)
			smallest = (array[b] < *smallest) ? (array + b) : smallest;

		if ((array + a) != smallest)
		{
			exchange_numbers(array + a, smallest);
			print_array(array, size);
		}
	}
}
