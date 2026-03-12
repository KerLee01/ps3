#include "push_swap.h"

static void sort_three(t_info *info)
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
}

static void butterfly_sort(t_info *a, t_info *b)
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
			rotate(a, b, false, false);
	}
}

static void is_reverse_push(t_info *a, t_info* b, size_t cost)
{
	bool reverse;

	reverse = false;
	if (cost <= b->total_nodes / 2)
		reverse = false;
	else
	{
		reverse = true;
		cost = b->total_nodes - cost;
	}
	while (cost > 0)
	{
		rotate(b, a, reverse, false);
		cost--;
	}
	push(b, a);
}

static void return_to_a(t_info *a, t_info *b)
{
	t_node *current;
	t_node *b_head;
	size_t max_cost;
	size_t cost;
	size_t max_rank;

	while (b->total_nodes > 0)
	{
		current = b->head;
		b_head = b->head;
		max_cost = 0;
		max_rank = 0;
		cost = 0;
		while (1)
		{
			if (current->rank > max_rank)
			{
				max_rank = current->rank;
				max_cost = cost;
			}
			cost++;
			current = current->next;
			if(current == b_head)
				break;
		}
		is_reverse_push(a, b, max_cost);
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
}
