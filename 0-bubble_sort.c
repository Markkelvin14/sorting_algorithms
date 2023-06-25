#include "sort.h"

/**
 * swap_elem - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_elem(int *a, int *b)
{
	int tmp_el;

	tmp_el = *a;
	*a = *b;
	*b = tmp_el;
}

/**
 * bubble_sort - Sort an array of integers in ascending order.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 */
void bubble_sort(int *array, size_t size)
{
	size_t m, length = size;
	bool bub = false;

	if (array == NULL || size < 2)
		return;

	while (bub == false)
	{
		bub = true;
		for (m = 0; m < length - 1; m++)
		{
			if (array[m] > array[m + 1])
			{
				swap_elem(array + m, array + m + 1);
				print_array(array, size);
				bub = false;
			}
		}
		length--;
	}
}
