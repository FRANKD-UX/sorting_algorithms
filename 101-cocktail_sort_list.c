#include "sort.h"

/**
 * swap_nodes - Swaps two adjacent nodes in a doubly linked list.
 * @left: Pointer to the left node.
 * @right: Pointer to the right node.
 */
void swap_nodes(listint_t *left, listint_t *right)
{
	listint_t *temp = right->next;

	if (left->prev)
		left->prev->next = right;
	if (right->next)
		right->next->prev = left;

	right->prev = left->prev;
	left->next = temp;
	right->next = left;
	left->prev = right;

	if (temp)
		temp->prev = left;

	/* Update the list head if necessary */
	if (right->prev == NULL)
	{
		*list = right; /* Update head if necessary */
	}
}

/**
 * cocktail_sort_list - Sorts a doubly linked list using the cocktail sort
 * algorithm.
 * @list: Pointer to the list to sort.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *head;
	int swapped = 1;

	if (list == NULL || *list == NULL)
		return;

	head = *list;
	while (swapped)
	{
		swapped = 0;

		/* Forward pass */
		while (head->next)
		{
			if (head->n > head->next->n)
			{
				swap_nodes(head, head->next);
				swapped = 1;
			}
			else
				head = head->next;
		}

		if (!swapped)
			break;

		swapped = 0;
		/* Backward pass */
		while (head->prev)
		{
			if (head->n < head->prev->n)
			{
				swap_nodes(head->prev, head);
				swapped = 1;
			}
			else
				head = head->prev;
		}
	}
}

