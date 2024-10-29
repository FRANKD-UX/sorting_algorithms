#include "sort.h"

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
		while (head->next)
		{
			if (head->n > head->next->n)
			{
				swap_nodes(head, head->next);
				swapped = 1;
			}
			head = head->next;
		}
		if (!swapped)
			break;
		swapped = 0;
		while (head->prev)
		{
			if (head->n < head->prev->n)
			{
				swap_nodes(head->prev, head);
				swapped = 1;
			}
			head = head->prev;
		}
	}
}

