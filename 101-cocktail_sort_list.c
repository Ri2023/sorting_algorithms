#include "sort.h"

void cocktail_sort_list(listint_t **list);
void swapForward(listint_t **list, listint_t **tail_ptr, listint_t **node_ptr);
void swapBackwards(listint_t **list, listint_t **tail_ptr,
listint_t **node_ptr);


/**
 * cocktail_sort_list -  custom cocktail sort algorithm
 *	to sort a doubly-linked list in ascending order
 * @list: pointer to the head
 *
 * Description: while printing swaps nodes and updates pointers
 */
void cocktail_sort_list(listint_t **list)
{
	bool is_sorted = false;
	listint_t *node_ptr, *tail_ptr;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}
	for (tail_ptr = *list; tail_ptr->next != NULL;)
		tail_ptr = tail_ptr->next;

	while (is_sorted == false)
	{
		is_sorted = true;
		for (node_ptr = *list; node_ptr != tail_ptr; node_ptr = node_ptr->next)
		{
			if (node_ptr->n > node_ptr->next->n)
			{
				swapForward(list, &tail_ptr, &node_ptr);
				print_list((const listint_t *)*list);
				is_sorted = false;
			}
		}
		for (node_ptr = node_ptr->prev; node_ptr != *list;
				node_ptr = node_ptr->prev)
		{
			if (node_ptr->n < node_ptr->prev->n)
			{
				swapBackwards(list, &tail_ptr, &node_ptr);
				print_list((const listint_t *)*list);
				is_sorted = false;
			}
		}
	}
}


/**
 * swapForward - switches a node forward in a doubly-linked list
 * @list: head pointer
 * @tail_ptr: tail pointer
 * @node_ptr: nodecocktail shaker algo current node
 */
void swapForward(listint_t **list, listint_t **tail_ptr, listint_t **node_ptr)
{
	listint_t *temporal;

	temporal = (*node_ptr)->next;

	if ((*node_ptr)->prev != NULL)
	{
		(*node_ptr)->prev->next = temporal;
	}

	else
	{
		*list = temporal;
	}

	temporal->prev = (*node_ptr)->prev;
	(*node_ptr)->next = temporal->next;

	if (temporal->next != NULL)
	{
		temporal->next->prev = *node_ptr;
	}

	else
	{
		*tail_ptr = *node_ptr;
	}

	(*node_ptr)->prev = temporal;
	temporal->next = *node_ptr;
	*node_ptr = temporal;
}

/**
 * swapBackwards - switches a node backwards in a doubly-linked list
 * @list: head pointer
 * @tail_ptr: tail pointer
 * @node_ptr: nodecocktail shaker algo current node
 */
void swapBackwards(listint_t **list, listint_t **tail_ptr,
listint_t **node_ptr)

{
	listint_t *temporal;

	temporal = (*node_ptr)->prev;

	if ((*node_ptr)->next != NULL)
	{
		(*node_ptr)->next->prev = temporal;
	}

	else
	{
		*tail_ptr = temporal;
	}
	temporal->next = (*node_ptr)->next;
	(*node_ptr)->prev = temporal->prev;

	if (temporal->prev != NULL)
	{
		temporal->prev->next = *node_ptr;
	}

	else
	{
		*list = *node_ptr;
	}

	(*node_ptr)->next = temporal;
	temporal->prev = *node_ptr;
	*node_ptr = temporal;
}

