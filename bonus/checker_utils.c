#include "push_swap.h"
#include "checker.h"

void c_swap(t_info *info)
{
	t_node *first;
	t_node *second;
	t_node *third;
	t_node *tail;

	if(!info->head || info->head->next == info->head)
		return;
	first = info->head;
	second = info->head->next;
	if(second->next == first)
	{
		info->head = second;
		return;
	}
	third = second->next;
	tail = first->prev;
	first->next = third;
	first->prev = second;
	second->prev = tail;
	second->next = first;
	third->prev = first;
	tail->next = second;
	info->head = second;
}

static void manage_push_dest(t_node *node, t_info *dest)
{
	if (!dest->head)
	{
		node->next = node;
		node->prev = node;
	}
	else
	{
		node->next = dest->head;
		node->prev = dest->head->prev;
		dest->head->prev->next = node;
		dest->head->prev = node;
	}
	dest->head = node;
}

void c_push(t_info *src, t_info *dest)
{
	t_node *node;
	t_node *tail;

	if (!src || !src->head || !dest)
		return;
	node = src->head;
	if (node->next == node)
		src->head = NULL;
	else
	{
		tail = node->prev;
		src->head = node->next;
		src->head->prev = tail;
		tail->next = src->head;
	}
	manage_push_dest(node, dest);
	src->total_nodes -= 1;
	dest->total_nodes += 1;	
}

void c_rotate(t_info *src, t_info *dest, bool reverse, bool together)
{
	if(!src->head || src->head->next == src->head)
		return;
	if(reverse == false)
		src->head = src->head->next;
	else
		src->head = src->head->prev;
	if(together == true)
	{
		if(!dest->head || dest->head->next == dest->head)
			return;
		if(reverse == false)
			dest->head = dest->head->next;
		else
			dest->head = dest->head->prev;
		return;
	}
}
