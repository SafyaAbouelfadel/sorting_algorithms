#include "deck.h"

/**
 * swap - swaps two nodes in a doubly-linked list
 * @first_node: the address of first node
 * @second_node: the address of second node
 *
 * Return: void
 */
void swap(deck_node_t *first_node, deck_node_t *second_node)
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
*tail_traverse- function that sorts from the tail back
*
*@head: head of list
*@tail: end of list
*@list: list being traversed
*
*Return: new head of the list
*/
deck_node_t *tail_traverse(deck_node_t *head,
	deck_node_t *tail, deck_node_t *list)
{
	(void) list;

	while (tail && tail->prev)
	{
		if (less_than(tail->card, tail->prev->card, 1))
		{
			swap(tail->prev, tail);
			if (tail->prev == NULL)
				list = tail;
		}
		else
			tail = tail->prev;
		if (tail->prev == NULL)
			head = tail;
	}
	return (head);
}

/**
*cocktail_sort_list - sorts linked list using cocktail shaker sort
*
*@list: doubly linked list to be sorted
*/
void cocktail_sort_list(deck_node_t **list)
{
	deck_node_t *tail, *head, *legth;
	int i = 0, j = 0, swaped = 1;

	if (!*list)
		return;
	legth = *list;
	for (i = 0; legth; i++)
	{
		legth = legth->next;
	}
	if (i < 2)
		return;
	head = *list;
	while (j < i)
	{
		swaped = 0;
		while (head && head->next)
		{
			if (less_than(head->card, head->next->card, 0))
			{
				swap(head, head->next);
				swaped++;
				if (head->prev->prev == NULL)
					*list = head->prev;
			}
			else
				head = head->next;
			if (head->next == NULL)
				tail = head;
		}
		head = tail_traverse(head, tail, *list);
		*list = head;
		j++;
	}
}


/**
*sort_deck- function that sorts a deck
*
*@deck: deck to be sorted
*/
void sort_deck(deck_node_t **deck)
{
	cocktail_sort_list(deck);
}

/**
*less_than - function that compares two nodes
*
*@a: first node
*@b: second node
*@flag: determines which comparison is done based on direction
* list is being traversed in
*
*Return: 1 if in place 0 if not in place
*/
int less_than(const card_t *a, const card_t *b, int flag)
{

	char *s1, *s2, *values[] = {"King", "Queen", "Jack", "10",
		"9", "8", "7", "6", "5", "4", "3", "2", "Ace"};
	int val_a = 0, val_b = 0, i = 0;

	for (i = 0; i < 13; i++)
	{
		for (s1 = (char *)a->value, s2 = values[i]; *s1 && *s1 == *s2; ++s1, ++s2)
			;
		if (*s1 == 0 && *s2 == 0)
		{
			val_a = i;
			break;
		}
	}
	for (i = 0; i < 13; i++)
	{
		for (s1 = (char *)b->value, s2 = values[i]; *s1 && *s1 == *s2; ++s1, ++s2)
			;
		if (*s1 == 0 && *s2 == 0)
		{
			val_b = i;
			break;
		}
	}
	if (!flag)
	{
		if (a->kind == b->kind)
			return (val_a < val_b);
		return (a->kind > b->kind);

	}
	if (a->kind == b->kind)
		return (val_a > val_b);
	return (a->kind < b->kind);
}
