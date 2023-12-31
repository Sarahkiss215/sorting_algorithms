#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * @array: pointer to array
 * @size: size of the array
 *
 * Return: Nothing.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j, n;

	for (; i < size; i++)
	{
		for (j = 1; j < size - i; j++)
		{
			if (array[j - 1] > array[j])
			{
				n = array[j];
				array[j] = array[j - 1];
				array[j - 1] = n;
				print_array(array, size);
			}
		}
	}
}
