#include "sort.h"

/**
 * list_len - function returns length of list
 * @list: head of list
 *
 * Return: length
 */

size_t list_len(listint_t *list)
{
	size_t length = 0;

	while (list)
	{
		length++;
		list = list->next;
	}
	return (length);
}

/**
 * switch_nodes - function will swap nodes at pointer p with the following node
 * @list: head of list
 * @p: pointer to node
 */

void switch_nodes(listint_t **list, listint_t **p)
{
	listint_t *a, *b, *c, *d;

	a = (*p)->prev;
	b = *p;
	c = (*p)->next;
	d = (*p)->next->next;
	two->next = d;
	if (d)
		d->prev = b;
	c->next = b;
	c->prev = b->prev;
	if (a)
		a->next = c;
	else
		*list = c;
	b->prev = c;
	*p = c;
}

/**
 * cocktail_sort_list - function sorts a doubly linked list using
 * the cocktail sort algorithm
 * @list: pointer to list
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *p;
	int s = 0;

	if (!list || !*list || list_len(*list) < 2)
		return;
	p = *list;
	while (!s)
	{
		s = 1;
		while (p->next)
		{
			if (p->n > p->next->n)
			{
				s = 0;
				switch_nodes(list, &p);
				print_list(*list);
			}
			else
				p = p->next;
		}
		if (s)
			break;
		p = p->prev;
		while (p->prev)
		{
			if (p->n < p->prev->n)
			{
				s = 0;
				p = p->prev;
				switch_nodes(list, &p);
				print_list(*list);
			}
			else
				p = p->prev;
		}
	}
}
