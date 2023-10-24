#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order
 * @array: Pointer to the array
 * @size: Size of the array
 *
 * Return: Nothing.
 */
void shell_sort(int *array, size_t size)
{
	size_t interval = 1, i;
	size_t index = 0;

	if (array == NULL || size < 2)
	{
		return;
	}
	while (interval < size / 3)
		interval = 3 * interval + 1;
	while (interval >= 1)
	{
		for (i = interval; i < size; i++)
			for (index = i; index >= interval &&
			 (array[index] < array[index - interval]); index -= interval)
				swap(array, index, index - interval);
		print_array(array, size);
		interval /= 3;
	}
}

/**
 * swap - swaps the positions of two elements into an array
 * @array: pointer to array
 * @f1: first element
 * @f2: second element
 *
 * Return: Nothing.
 */
void swap(int *array, ssize_t f1, ssize_t f2)
{
	int tmp;

	tmp = array[f1];
	array[f1] = array[f2];
	array[f2] = tmp;
}
