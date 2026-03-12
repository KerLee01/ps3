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

t_info *create_info(char group, char push_to, int total_nodes, t_node *head)
{
	t_info *info;

	info = malloc(sizeof(t_info));
	if(info == NULL)
		return NULL;
	info->group = group;
	info->push_to = push_to;
	info->total_nodes = total_nodes;
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
	a_info = create_info('a', 'b', argc - 1, a_list);
	if(a_info == NULL)
		return -1;
	b_info = create_info('b', 'a', 0, b_list);
	if(b_info == NULL)
		return -1;
	sort_stack(a_info, b_info);
	free_nodes(&a_info->head);
	free(a_info);
	free_nodes(&b_info->head);
	free(b_info);
	return 0;
}
