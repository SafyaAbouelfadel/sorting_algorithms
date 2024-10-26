#include "sort.h"

/**
 * swap - swaps two nodes in a doubly-linked list
 * @first_node: the address of first node
 * @second_node: the address of second node
 *
 * Return: void
 */
void swap(listint_t *first_node, listint_t *second_node)
{
	if (first_node->prev)
		first_node->prev->next = second_node;
	if (second_node->next)
		second_node->next->prev = first_node;
	first_node->next = second_node->next;
	second_node->prev = first_node->prev;
	first_node->prev = second_node;
	second_node->next = first_node;

}

/**
 * insertion_sort_list - insert sort a doubly-linked list
 * @list: address of pointer to head node
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current_node, *comp_node;

	if (!list || !*list || !(*list)->next)
		return;
	current_node = (*list)->next;
	while (current_node)
	{
		comp_node = current_node;
		current_node = current_node->next;
		while (comp_node && comp_node->prev)
		{
			if (comp_node->prev->n > comp_node->n)
			{
				swap(comp_node->prev, comp_node);
				if (!comp_node->prev)
					*list = comp_node;
				print_list((const listint_t *)*list);
			}
			else
				comp_node = comp_node->prev;
		}

	}
}
