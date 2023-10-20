#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * @array: pointer to the array
 * @size: size of array
 *
 * Return: Nothing.
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0, j;
	int tmp, swap, flag = 0;

	if (array == NULL)
	{
		return;
	}
	for (; i < size; i++)
	{
		tmp = i;
		flag = 0;
		for (j = i + 1; j < size; j++)
		{
			if (array[tmp] > array[j])
			{
				tmp = j;
				flag += 1;
			}
		}
		swap = array[i];
		array[i] = array[tmp];
		array[tmp] = swap;
		if (flag != 0)
			print_array(array, size);
	}
}
