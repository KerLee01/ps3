*This project has been created as part of the 42 curriculum by kerlee.*

## Description
This project is **push_swap**. It is a highly structured algorithm challenge. There is a set of integer values, 2 stacks, and a set of instructions to manipulate both stacks to complete this project. The goal is to calculate and display the shortest sequence of push_swap instructions needed to sort the given integers.

## Instructions
** The libft project is not utilized in this project.**
** The ft_printf project is utilized in this project.**

The project utilizes a Makefile with standard rules:

```
make            # Compiles the library libftprintf.a
make clean      # Removes object files
make fclean     # Removes object files and the library
make re         # Recompiles everything

```

## Prerequisites
- GCC or Clang compiler
- Make

## Compilation

## Resources
- Medium Articles

## Testing
1. Manual Edge Case
    - Testing if program outputs an error when the values used causes an integer overflow, when there are duplicates in the set of integer values, when there are values in the integer set that is/are not integers.
    - Testing when argument counts (not including executable file), is 1, 2, 3, 4 and more than 4, as all are executed differently.
2. Memory Analysis
    - No leaks on Valgrind as malloc is used.

## Directory Structure

## Additional Information

The algorithm applied in this program is the Butterfly Algrithm (also known as a highly optimised Rank-Sort). The project instruction allows us to sort the integer set using 2 stacks, set A and set B. 

The operations that can be to sort the stacks are:
(Swap : swapping the first 2 elements at the top of the stack)
- sa (swap a)
- sb (swap b)
- ss (swap a and b at the same time)

(Push : Taking the first element from the source stack and put it at the top of the destined stack)
- pa (push a: taking first element at the top of b and put it at the top of a)
- pb (push b: taking first element at the top of a and put it at the top of b)

(Rotate : Shift up all elements of a stack by 1)
- ra (rotate a)
- rb (rotate b)
- rr (rotate a and b at the same time)

(Reverse Rotate : Shift down all the elemets of a stack by 1)
- rra (reverse rotate a)
- rrb (reverse rotate b)
- rrr (reverse rotate a and b together)

** The output of the program (sorted set of integers) can be checked using the function below: **
```
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

```
