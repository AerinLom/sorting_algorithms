#include "sort.h"

/**
 * lomuto_separate - Order a subset of an array of numbers
 *                      in Lomuto style
 * @array: array of numbers.
 * @size: size of array
 * @left: beginning index
 * @right: end index
 * Return: complete index
 */
int lomuto_separate(int *array, size_t size, int left, int right)
{
	int *change, top, bottom;

	change = array + right;

	for (top = bottom = left; bottom < right; bottom++)
	{
		if (array[bottom] < *change)
		{
			if (top < bottom)
			{
				exchange_numbers(array + bottom, array + top);
				print_array(array, size);
			}
			top++;
		}
	}

	if (array[top] > *change)
	{
		exchange_numbers(array + top, change);
		print_array(array, size);
	}
	return (top);
}

/**
 * lomuto_sort_recursion - Implement the quicksort algorithm through recursion
 * @array: An array of numbers to sort
 * @size: size of array
 * @left: beginning index
 * @right: end index
 */
void lomuto_sort_recursion(int *array, size_t size, int left, int right)
{
	int comp;

	if (right - left > 0)
	{
		comp = lomuto_separate(array, size, left, right);
		lomuto_sort_recursion(array, size, left, comp - 1);
		lomuto_sort_recursion(array, size, comp + 1, right);
	}
}

/**
 * quick_sort - Sort array of numbers using quick sort
 * @array: array of numbers
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort_recursion(array, size, 0, size - 1);
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
