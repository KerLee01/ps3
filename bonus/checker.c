#include "push_swap.h"
#include "checker.h"
#include "get_next_line.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*us1;
	unsigned char	*us2;

	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	while (n != 0 && *us1 && *us2)
	{
		if (*us1 > *us2)
			return (1);
		if (*us1 < *us2)
			return (-1);
		us1++;
		us2++;
		n--;
	}
	if (*us1 && n != 0)
		return (1);
	if (*us2 && n != 0)
		return (-1);
	return (0);
}

int call_moves(char *line, t_info *a, t_info *b)
{
	if(ft_strncmp(line, "sa\n", 3) == 0)
		c_swap(a);
	else if(ft_strncmp(line, "sb\n", 3) == 0)
		c_swap(b);
	else if(ft_strncmp(line, "pa\n", 3) == 0)
		c_push(b, a);
	else if(ft_strncmp(line, "pb\n", 3) == 0)
		c_push(a, b);
	else if(ft_strncmp(line, "ra\n", 3) == 0)
		c_rotate(a, b, false, false);
	else if(ft_strncmp(line, "rb\n", 3) == 0)
		c_rotate(b, a, false, false);
	else if(ft_strncmp(line, "rr\n", 3) == 0)
		c_rotate(a, b, false, true);
	else if(ft_strncmp(line, "rra\n", 4) == 0)
		c_rotate(a, b, true, false);
	else if(ft_strncmp(line, "rrb\n", 4) == 0)
		c_rotate(b, a, true, false);
	else if(ft_strncmp(line, "rrr\n", 4) == 0)
		c_rotate(a, b, true, true);
	else
		return(write(2, "ERROR\n", 6), -1);
	return 0;
}


int get_line_move(t_info *a, t_info *b)
{
	char *line;

	line = get_next_line(0);
	while(line != NULL)
	{
		if(call_moves(line, a, b) == -1)
			return -1;
		line = get_next_line(0);
	}
	return 0;
}

bool is_sorted(t_info *a, t_info *b)
{
	t_node *current;
	size_t i;

	current = a->head;
	i = 1;
	if(b->total_nodes != 0)
		return false;
	while(i < a->total_nodes)
	{
		if(current->rank > current->next->rank)
			return false;
		current = current->next;
		i++;
	}
	return true;
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
		return (free_nodes(&a_list), -1);
	a_info = create_info('a', 'b', argc - 1, a_list);
	b_info = create_info('b', 'a', 0, b_list);
	if(a_info == NULL || b_info == NULL)
		return -1;
	if(get_line_move(a_info, b_info) == -1)
		return -1;
	if(is_sorted(a_info, b_info) == false)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	free_nodes(&a_info->head);
	free(a_info);
	free_nodes(&b_info->head);
	free(b_info);
	return 0;
}





