#include "sort.h"
#include <stdio.h> 

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order
 * using the Insertion sort algorithm.
 * @list: double pointer to the head of the doubly linked list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *next_node, *temp;

	if (!list || !*list || !(*list)->next)
		return;

	current = (*list)->next;
	while (current)
	{
		next_node = current->next;
		while (current->prev && current->n < current->prev->n)
		{
			/* Swap current node with the previous node */
			temp = current->prev;
			temp->next = current->next;
			if (current->next)
				current->next->prev = temp;

			current->next = temp;
			current->prev = temp->prev;
			temp->prev = current;

			if (current->prev)
				current->prev->next = current;
			else
				*list = current;

			temp->next = current;

			/* Print list after every swap */
			print_list(*list);
		}
		current = next_node;
	}
}

