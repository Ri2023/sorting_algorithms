#include "sort.h"

void nodeSwapper(listint_t **head, listint_t **_1st_node,
listint_t *_2nd_node);

/**
 * insertion_sort_list - custom insertion sort algorithm
 *	to sort a doubly-linked list in ascending order
 * @list: pointer to the head
 *
 * Description: while printing swaps nodes and updating pointers
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;
	listint_t *insertionPoint;
	listint_t *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}

	/* For each element, it finds the correct insertion point by */
	/* comparing it with the previous elements in*/
	/* the sorted portion of the list */
	for (current = (*list)->next; current != NULL; current = temp)
	{
		temp = current->next;

		insertionPoint = current->prev;

		while (insertionPoint != NULL && current->n < insertionPoint->n)
		{
			nodeSwapper(list, &insertionPoint, current);
			print_list((const listint_t *)*list);
		}
	}
}

/**
 * nodeSwapper - swaps positions of two nodes in a doubly-linked list
 * @head: pointer to the head
 * @_1st_node: first node pointer to be swapped
 * @_2nd_node: second node pointer to be swapped
 */
void nodeSwapper(listint_t **head, listint_t **_1st_node, listint_t *_2nd_node)
{
	(*_1st_node)->next = _2nd_node->next;

	if (_2nd_node->next != NULL)
	{
		_2nd_node->next->prev = *_1st_node;
	}

	_2nd_node->prev = (*_1st_node)->prev;
	_2nd_node->next = *_1st_node;

	if ((*_1st_node)->prev != NULL)
	{
		(*_1st_node)->prev->next = _2nd_node;
	}

	else
	{
		*head = _2nd_node;
	}

	(*_1st_node)->prev = _2nd_node;
	*_1st_node = _2nd_node->prev;
}
