#include "sort.h"
#include <stdio.h>

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Pointer to the head of the linked list
 * @left: Node to be swapped with its next node
 * @right: Node to be swapped with its previous node
 */
void swap_nodes(listint_t **list, listint_t *left, listint_t *right)
{
	if (left == NULL || right == NULL || list == NULL || *list == NULL)
		return;
	if (left->prev)
		left->prev->next = right;
	else
		*list = right;

	if (right->next)
		right->next->prev = left;

	if (left->next != right)
	{
		left->next = right->next;
		right->next = left;
	}
	else
	{
		left->next = right->next;
		right->next = left;
	}

	if (left->prev != right)
	{
		right->prev = left->prev;
		left->prev = right;
	}
	else
	{
		right->prev = left->prev;
		left->prev = right;
	}
	print_list(*list);
}


/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 *                      in ascending order using Cocktail Shaker sort
 * @list: Pointer to the head of the linked list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *start = NULL;
	listint_t *end = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	do {
		swapped = 0;
		for (start = *list; start->next != end; start = start->next)
		{
			if (start->n > start->next->n)
			{
				swap_nodes(list, start, start->next);
				swapped = 1;
			}
		}
		if (swapped == 0)
			break;

		end = start;

		swapped = 0;
		for (start = end->prev; start != NULL; start = start->prev)
		{
			if (start->n > start->next->n)
			{
				swap_nodes(list, start, start->next);
				swapped = 1;
			}
		}
		end = start;
	} while (swapped);
}
