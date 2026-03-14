*This project has been created as part of the 42 curriculum by kerlee.*

## Description
This project is **push_swap**. It is a highly structured algorithm challenge. There is a set of integer values, 2 stacks, and a set of instructions to manipulate both stacks to complete this project. The goal is to calculate and display the shortest sequence of push_swap instructions needed to sort the given integers.

## Instructions
** The get_next_line project is utilized in the bonus part of this project.**

The project utilizes a Makefile with standard rules:

```
make            # Compiles the mandatory part
make bonus      # Compiles the checker (bonus)
make clean      # Removes object files
make fclean     # Removes object files and the library
make re         # Recompiles everything

```

## Prerequisites
- GCC or Clang compiler
- Make

## Compilation
For Mandatory part:
- Run make to obtain the push_swap program.
- Use the integer set of your choice, together with the program (e.g ./push_swap 3 1 2)
- The program will then output the moves to sort the set of integers in ascending order.

** To use the checker made in the bonus to check the mandatory program, you must have done what is necessary for the mandatory part, stated above **
For Bonus:
- Run make bonus to obtain the checker program.
- To run by itself:
    > Run the program (e.g ./push_swap 3 2 1).
    > The program will now wait for the instructions inserted into the terminal.
    > Once done, press (Ctrl + D).
- To run with push swap program:
    > ARG="4 67 3 87 23"; ./push_swap $=ARG | ./checker $=ARG 
    OR (for larger set of random integers)
    > ARG=$(shuf -i 1-1000 -n 100 | tr '\n' ' ')
    > ./push_swap $=ARG | ./checker $=ARG

(For both uses of the bonus, the checker will display OK if the instructions successfully sorts the set, and KO otherwise. If the checker displays ERROR, there are a few cases : the instruction does not exist, the integer set contains duplicates / not all are integers / is bigger than an integer / is incorrectly formatted.)

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

## Resources
- Medium Articles

## Testing
1. Manual Edge Case
    - Testing if program outputs an error when the values used causes an integer overflow, when there are duplicates in the set of integer values, when there are values in the integer set that is/are not integers.
    - Testing when argument counts (not including executable file), is 1, 2, 3, 4 and more than 4, as all are executed differently.
2. Memory Analysis
    - No leaks on Valgrind as malloc is used.

## Directory Structure
```
.
├── bonus
│   ├── checker.c
│   ├── checker.h
│   ├── checker_utils.c
│   └── get_next_line
│       ├── get_next_line_bonus.c
│       ├── get_next_line_bonus.h
│       ├── get_next_line.c
│       ├── get_next_line.h
│       ├── get_next_line_utils_bonus.c
│       ├── get_next_line_utils.c
│       └── README.md
├── create_list.c
├── fill_list.c
├── Makefile
├── push_swap.c
├── push_swap.h
├── README.md
├── sort_stack.c
└── sort_utils.c

3 directories, 18 files
```

## Additional Information

The algorithm applied in this program is the Butterfly Algrithm (also known as a highly optimised Rank-Sort). The program first pushes based on a sliding mathematical window from a stack to b stack creating a V-shape in B. This makes pushing back from B to A incredibly cheap. The project instruction allows us to sort the integer set using 2 stacks, set A and set B. 

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
