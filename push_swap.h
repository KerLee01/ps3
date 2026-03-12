#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct s_node
{
   int value;
   size_t rank;
   size_t cost;
   struct s_node *prev;
   struct s_node *next;
} t_node;

typedef struct s_info
{
   char group;
   char push_to;
   size_t total_nodes;
   t_node *head;
} t_info;

#ifndef ERROR_INT
#define ERROR_INT 2147483648
#endif

// push_swap.c
void print_list(t_node *list); //remove

// create_list.c
t_node *new_node(int num, int rank);
void attach_back(t_node *new, t_node **list);
void free_nodes(t_node **list);

// fill_list.c
bool check_duplicate(t_node **list, int num, int *num_rank);
long find_check_num(t_node **list, char *num_str, int *num_rank);
int check_insert_input(t_node **list, int argc, char **argv);

// sort_utils.c
void swap(t_info *info);
void push(t_info *src, t_info *dest);
void rotate(t_info *src, t_info *dest, bool reverse, bool together);

// sort_stack.c
void sort_stack(t_info *a_info, t_info *b_info);
#endif
