#include "push_swap.h"

void sort_three(t_info *info)
{
	t_node *first = info->head;
	t_node *second = first->next;
	t_node *third = second->next;

	if (first->rank > second->rank && first->rank > third->rank)
		rotate(info, info, false, false);
	else if (second->rank > first->rank && second->rank > third->rank)
		rotate(info, info, true, false);
		
	first = info->head;
	second = first->next;
	
	if (second->rank < first->rank)
		swap(info);
		
	info->max = info->head->next->next;
	info->min = info->head;
}

void butterfly_sort(t_info *a, t_info *b)
{
	int chunk;
	size_t counter;

	counter = 1;
	if (a->total_nodes <= 100)
		chunk = 15;
	else
		chunk = 30;

	while (a->total_nodes > 0)
	{
		if (a->head->rank <= counter)
		{
			push(a, b);
			counter++;
		}
		else if (a->head->rank <= counter + chunk)
		{
			push(a, b);
			rotate(b, a, false, false);
			counter++;
		}
		else
		{
			rotate(a, b, false, false);
		}
	}
}

void return_to_a(t_info *a, t_info *b)
{
	t_node *current;
	size_t max_pos;
	int max_rank;
	int pos;
	int cost;
	bool reverse;

	while (b->total_nodes > 0)
	{
		current = b->head;
		max_pos = 0;
		max_rank = -1;
		pos = 0;

		while (current != b->head)
		{
			if ((int)current->rank > max_rank)
			{
				max_rank = current->rank;
				max_pos = pos;
			}
			pos++;
			current = current->next;
		} 

		if (max_pos <= b->total_nodes / 2)
		{
			reverse = false;
			cost = max_pos;
		}
		else
		{
			reverse = true;
			cost = b->total_nodes - max_pos;
		}

		while (cost > 0)
		{
			rotate(b, a, reverse, false);
			cost--;
		}
		push(b, a);
	}
}

void sort_stack(t_info *a, t_info *b)
{
	if (a->total_nodes <= 1)
		return;

	if (a->total_nodes == 2)
	{
		if (a->head->value > a->head->next->value)
			swap(a);
		return;
	}
	
	if (a->total_nodes == 3)
	{
		sort_three(a);
		return;
	}

	butterfly_sort(a, b);
	return_to_a(a, b);
	print_list(a->head);
}
