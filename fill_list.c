#include "push_swap.h"

bool check_duplicate(t_node **list, int num, int *num_rank)
{
	t_node *head;
	t_node *current;
	int on_top;

	if(!list)
		return false;
	if(!(*list))
		return ((*num_rank) = 1, false);
	current = *list;
	head = *list;
	*num_rank = 0;
	on_top = 0;
	while(1)
	{
		if(current->value == num)
			return true;
		if(current->value < num)
			on_top += 1;
		if(current->value > num)
			current->rank += 1;
		current = current->next;
		if(current == head)
			return ((*num_rank) = on_top + 1, false);
	}
	return false;
}

long find_check_num(t_node **list, char *num_str, int *num_rank)
{
	int i;
	long num;
	int negative;

	i = 0;
	num = 0;
	negative = 1;
	while(num_str[i] != '\0')
	{
		num *= 10;
		if(i == 0 && num_str[i] == '-')
			negative = -1;
		else if(num_str[i] >= '0' && num_str[i] <= '9')
			num += num_str[i] - '0';
		else
			return (printf("ERROR\n"), ERROR_INT); // alphabeth found
		i++;
	}
	num *= negative;
	if(num < INT_MIN || num > INT_MAX)
		return (printf("ERROR\n"), ERROR_INT); // out of bound
	if(check_duplicate(list, num, num_rank) == true)
		return(printf("ERROR\n"), ERROR_INT);
	return (num);
}

int check_insert_input(t_node **list, int argc, char **argv)
{
	t_node *node;
	int i;
	long num;
	int num_rank;

	i = 1;
	while(i < argc)
	{
		num_rank = 0;
		num = find_check_num(list, argv[i], &num_rank);
		if(num == ERROR_INT)
			return (-1);
		else
		{
			node = new_node(num, num_rank);
			if(node == NULL)
				return (-1);
			attach_back(node, list);
		}
		i++;
	}
	return 0;
}
