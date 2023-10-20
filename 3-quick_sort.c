#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending order
 * @array: pointer to array
 * @size:  sizeof array
 *
 * Return: Nothing.
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	q_sort(array, 0, size - 1, size);
}

/**
 * q_sort - qucksort algorithm implementation
 * @array: pointer to array
 * @size: size of array
 * @n1: first element in the array
 * @n2: last element in the array
 *
 * Return: Nothing.
 */
void q_sort(int *array, ssize_t n1, ssize_t n2, int size)
{
	ssize_t index = 0;

	if (n1 < n2)
	{
		index = lomuto_partition(array, n1, n2, size);

		q_sort(array, n1, index - 1, size);
		q_sort(array, index + 1, n2, size);
	}
}

/**
 * lomuto_partition - lomuto partition sorting scheme implementation
 * @array: pointer to array
 * @size: size of array
 * @n1: first element in the array
 * @n2: last element in the array
 *
 * Return: position of the last element sorted
 */
int lomuto_partition(int *array, ssize_t n1, ssize_t n2, size_t size)
{
	int pivot = array[n2];
	ssize_t current = n1, finder;

	for (finder = n1; finder < n2; finder++)
	{
		if (array[finder] < pivot)
		{
			if (array[current] != array[finder])
			{
				swap(array, current, finder);
				print_array(array, size);
			}
			current++;
		}
	}
	if (array[current] != array[n2])
	{
		swap(array, current, n2);
		print_array(array, size);
	}
	return (current);
}

/**
 * swap - swaps the positions of two elements into an array
 * @array: pointer to array
 * @f1: first element
 * @f2: second element
 *
 * Return: Nothing.
 */
void swap(int *array,ssize_t f1, ssize_t f2)
{
	int tmp;

	tmp = array[f1];
	array[f1] = array[f2];
	array[f2] = tmp;
}
