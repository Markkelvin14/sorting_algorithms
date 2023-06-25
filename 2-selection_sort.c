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
 * selection_sort - Sort an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *bre;
	size_t m, k;

	if (array == NULL || size < 2)
		return;

	for (m = 0; m < size - 1; m++)
	{
		bre = array + m;
		for (k = m + 1; k < size; k++)
			bre = (array[k] < *bre) ? (array + k) : bre;

		if ((array + m) != bre)
		{
			swap_elem(array + m, bre);
			print_array(array, size);
		}
	}
}
