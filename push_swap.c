#include "push_swap.h"

void print_list(t_node *list)
{
	t_node *head;
	t_node *node;

	if(!list)
		return;
	head = list;
	node = list;
	while(1)
	{
		printf("rank: %zu, value: %d\n", node->rank, node->value);
		node = node->next;
		if(node == head)
			break;
	}
}
t_info *create_info(char group, int total_nodes, t_node *head, bool ascending)
{
	t_info *info;

	info = malloc(sizeof(t_info));
	if(info == NULL)
		return NULL;
	info->group = group;
	info->ascending = ascending;
	info->counter = 0;
	info->end_range = 0;
	info->part = 0;
	info->max = 0;
	info->min = 0;
	info->total_nodes = total_nodes;
	info->min_cost = NULL;
	info->target = NULL;
	info->head = head;
	return info;
}

int main(int argc, char **argv)
{
	t_info *a_info;
	t_info *b_info;
	t_node *a_list = NULL;
	t_node *b_list = NULL;

	if(argc < 2)
		return -1;
	if(check_insert_input(&a_list, argc, argv) == -1)
	{
		free_nodes(&a_list);
		return -1;
	}
	a_info = create_info('a', argc - 1, a_list, true);
	b_info = create_info('b', 0, b_list, false);
	sort_stack(a_info, b_info);
	/*
	printf("Before:\n");
	print_list(a_info->head);
	sort_stack(a_info, b_info);
	printf("After:\nA:\n");
	print_list(a_info->head);
	printf("B:\n");
	print_list(b_info->head);
	*/
	//print_list(a_info->head);
	free_nodes(&a_info->head);
	free_nodes(&b_info->head);

	return 0;
}
