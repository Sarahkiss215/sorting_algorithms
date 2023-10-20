#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order
 * @list: list to be sorted
 *
 * Return: Nothing.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node;

	if (list == NULL || (*list)->next == NULL)
		return;
	node = (*list)->next;
	while (node)
	{
		while ((node->prev) && (node->prev->n > node->n))
		{
			node = swap_node(node, list);
			print_list(*list);
		}
		node = node->next;
	}
}

/**
 * swap_node - swaps a node
 * @node: node
 * @list: list to be treated
 *
 * Return: return a pointer to a node
 */
listint_t *swap_node(listint_t *node, listint_t **list)
{
	listint_t *prevnode = node->prev, *currentnode = node;

	prevnode->next = currentnode->next;
	if (currentnode->next)
	{
		currentnode->next->prev = prevnode;
	}
	currentnode->next = prevnode;
	currentnode->prev = prevnode->prev;
	prevnode->prev = currentnode;
	if (currentnode->prev)
	{
		currentnode->prev->next = currentnode;
	}
	else
	{
		*list = currentnode;
	}
	return (currentnode);
}
