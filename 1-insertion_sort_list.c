#include "sort.h"

/**
 * node_flip - Swaps two nodes in a doubly-linked list.
 * @list: A pointer to the head of the doubly-linked list.
 * @current_ptr: Pointer to the node to insert.
 * @exp_node: The node to be swapped with.
 */
void node_flip(listint_t **list, listint_t **current_ptr, listint_t *exp_node)
{
	(*current_ptr)->next = exp_node->next;

	if (exp_node->next)
		exp_node->next->prev = *current_ptr;

	exp_node->prev = (*current_ptr)->prev;
	exp_node->next = *current_ptr;

	if ((*current_ptr)->prev)
		(*current_ptr)->prev->next = exp_node;

	else
		*list = exp_node;

	(*current_ptr)->prev = exp_node;
	*current_ptr = exp_node->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       using the insertion sort algorithm.
 * @list: A pointer to the head of the doubly-linked list of integers.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current_node, *inserted_node, *next_node;

	if (!list || !*list || !(*list)->next)
	{
		return;
	}

	current_node = (*list)->next;
	while (current_node != NULL)
	{
		next_node = current_node->next;
		inserted_node = current_node->prev;
		while (inserted_node != NULL && current_node->n < inserted_node->n)
		{
			node_flip(list, &inserted_node, current_node);
			print_list((const listint_t *)*list);
		}
		current_node = next_node;
	}
}

