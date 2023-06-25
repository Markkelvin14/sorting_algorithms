#include "sort.h"

void swap_elem(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

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
 * lomuto_part - Order a subset of an array of integers
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int lomuto_part(int *array, size_t size, int left, int right)
{
	int *piv, up, down;

	piv = array + right;
	for (up = down = left; down < right; down++)
	{
		if (array[down] < *piv)
		{
			if (up < down)
			{
				swap_elem(array + down, array + up);
				print_array(array, size);
			}
			up++;
		}
	}

	if (array[up] > *piv)
	{
		swap_elem(array + up, piv);
		print_array(array, size);
	}

	return (up);
}

/**
 * lom_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 */
void lom_sort(int *array, size_t size, int left, int right)
{
	int p;

	if (right - left > 0)
	{
		p = lomuto_part(array, size, left, right);
		lom_sort(array, size, left, p - 1);
		lom_sort(array, size, p + 1, right);
	}
}

/**
 * quick_sort - Sort an array of integers in ascendingorder using the quicksort
 * @array: An array of integers.
 * @size: The size of the array.
 * Description: Uses the Lomuto partition scheme. Prints the array after swap
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lom_sort(array, size, 0, size - 1);
}
