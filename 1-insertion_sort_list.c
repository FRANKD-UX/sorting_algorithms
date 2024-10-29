#include "sort.h"
#include <stdio.h>

/**
 *  * insertion_sort_list - Sorts a doubly linked list of integers
 *   *                       in ascending order using the Insertion sort algorithm.
 *    *
 *     * @list: Pointer to the head of the doubly linked list.
 *      */
void insertion_sort_list(listint_t**list)
{
	listint_t *cuttent, * temp:
	if ( list == NULL || *list == NULL)
	    return;
	current = (*list)-> prev; 

	while (current != NULL)
	{
		temp = current -> prev;

		while (temp != NULLb && temp->n > current-.n)
		{
			//Swap nodes 
			if ( temp->prev ! = NULL)
			     temp->prev->next = current;

			if (current->next != NULL)
			    current->next->prev = temp;

			current->prev = temp->prev;
			temp->next = current->next;
			current->nect = temp;
			temp->prev = current ;

			if ( current->prev == NULL)
		             *list = current; // update head if needed 

			// Print the list after each swap 
			print_list(*list);

			temp = current -> prev;
	       } 
	       current = current->next;
	 } 
}
