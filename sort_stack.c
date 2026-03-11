#include "push_swap.h"

void sort_three(t_info *info)
{
        t_node *first;
        t_node *second;
        t_node *third;

        first = info->head;
        second = first->next;
        third = second->next;

        if(first->rank > second->rank && first->rank > third->rank)
                rotate(info, info, false, false);
        else if(second->rank > first->rank && second->rank > third->rank)
                rotate(info, info, true, false);
        first = info->head;
        second = first->next;
        if(second->rank < first->rank)
                swap(info);
	info->max = info->head->next->next;
	info->min = info->head;
}

void push_a_to_b(t_info *a)
{
	t_node *current;
	t_node *head;

	current = a->head;
	head = a->head;
	a->target = NULL;
	a->counter = 0;
	while(1)
	{
		while(current->rank > a->end_range)
		{
			a->counter++;
			current = current->next;
			if(current == head)
				return;
		}
		current->reverse = false;
		current->cost = a->counter;
		if(a->counter > a->total_nodes - a->counter)
		{
			current->reverse = true;
			current->cost = a->total_nodes - a->counter;
		}
		if(a->target == NULL || current->cost < a->target->cost)
			a->target = current;
		a->counter++;
		current = current->next;
		if(current == head)
			break;
	}
}

void find_bests(t_info *b)
{
	t_node *best;
	t_node *second;
	t_node *current;

	best = NULL;
	second = NULL;
	current = b->head;
	b->counter = 0;
	while(b->counter < b->total_nodes)
	{
		if(current->rank == b->total_nodes)
		{
			best = current;
			best->cost = b->counter;
			best->reverse = false;
			if(b->counter > b->total_nodes - b->counter)
			{
				best->cost = b->total_nodes - b->counter;
				best->reverse = true;
			}
		}
		else if(current->rank == b->total_nodes - 1)
		{
			second = current;
			second->cost = b->counter;
			second->reverse = false;
			if(b->counter > b->total_nodes - b->counter)
			{
				second->cost = b->total_nodes - b->counter;
				second->reverse = true;
			}
		}
		current = current->next;
		b->counter++;
	}
	if(second != NULL && best->cost > second->cost + 1)
		b->target = second;
	else
		b->target = best;
}

void larger_sorts(t_info *a, t_info *b)
{
	t_node *current;
	t_node *b_head;
	bool rotate_b;

	rotate_b = false;
	while(a->total_nodes > 0)
	{
		push_a_to_b(a);
		if(a->target == NULL)
		{
			a->end_range += a->part;
			if(a->end_range > a->total_nodes + b->total_nodes)
				a->end_range = a->total_nodes + b->total_nodes;
			continue;
		}
		if(a->head != a->target && rotate_b == true && a->target->reverse == false)
		{
			rotate(a, b, false, true);
			rotate_b = false;
		}
		while(a->head != a->target)
			rotate(a, b, a->target->reverse, false);
		if(rotate_b == true)
		{
			rotate(b, a, false, false);
			rotate_b = false;
		}
		push(a, b);
		if(b->head->rank <= a->end_range - (a->part / 2))
			rotate_b = true;
		if(b->total_nodes >= a->end_range)
		{
			a->end_range += a->part;
			if(a->end_range > a->total_nodes + b->total_nodes)
				a->end_range = a->total_nodes + b->total_nodes;
		}
	}
	if (rotate_b == true)
    		rotate(b, a, false, false);
	while(b->total_nodes > 0)
	{
		find_bests(b);
		if(b->target->rank == b->total_nodes - 1)
		{
			while(b->head != b->target)
				rotate(b, a, b->target->reverse, false);
			printf("\nA\n");
			push(b, a);

			current = b->head;
			b_head = b->head;
			b->counter  = 0;
			while(current->rank != b->total_nodes + 1)
			{
				b->counter++;
				current = current->next;
				if(current == b_head)
					break;
			}

			b->target = current;
			current->cost = b->counter;
			current->reverse = false;
			if(b->counter > b->total_nodes - b->counter)
			{
				current->cost = b->total_nodes - b->counter;
				current->reverse = true;
			}
			while(b->head->rank != b->total_nodes + 1)
				rotate(b, a, b->target->reverse, false);
			push(b, a);
			printf("\nA\n");

			swap(a);
		}
		else if(b->target->rank == b->total_nodes)
		{
			while(b->head != b->target)
				rotate(b, a, b->target->reverse, false);
			push(b, a);
			printf("\nA\n");

		}
	}
}

void sort_stack(t_info *a, t_info *b)
{
	a->part = 60;
	a->end_range = a->part;

        if(a->total_nodes == 1)
                return;
	else if(b->total_nodes == 2)
        {
                if((a->head->next)->value < a->head->value)
                        swap(a);
                return;
        }
	else if(a->total_nodes == 3)
        {
                sort_three(a);
                return;
        }
	else if(a->total_nodes == 4)
		push(a, b);
	else if(a->total_nodes > 4)
	{
		larger_sorts(a, b);
	}
}
