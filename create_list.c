#include "push_swap.h"

t_node *new_node(int num, int rank)
{
	t_node *node;

	node = malloc(sizeof(t_node));
	if(node == NULL)
		return NULL;
	node->value = num;
	node->rank = rank;
	node->cost = 0;
	node->prev = node;
	node->next = node;
	return (node);
}

void attach_back(t_node *new, t_node **list)
{
	t_node *tail;

	if(new == NULL || list == NULL)
		return;
	if(*list == NULL)
	{
		*list = new;
		(*list)->next = *list;
		(*list)->prev = *list;
	}
	else
	{
		tail = (*list)->prev;

		tail->next = new;
		new->prev = tail;

		new->next = (*list);
		(*list)->prev = new;
	}
}

void free_nodes(t_node **list)
{
	t_node *current;
	t_node *head;
	t_node *next_node;

	if(!list || !(*list))
		return;
	head = *list;
	current = head->next;
	while(current != head)
	{
		next_node = (current)->next;
		free(current);
		current = next_node;
	}
	free(head);
	*list = NULL;
}
