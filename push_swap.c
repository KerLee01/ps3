#include "push_swap.h"

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
