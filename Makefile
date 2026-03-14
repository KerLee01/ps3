NAME        = push_swap
BONUS_NAME  = checker

CC          = cc
CFLAGS      = -Wall -Wextra -Werror

INCLUDES    = -I. -I./bonus/get_next_line

SHARED_SRCS = create_list.c \
              fill_list.c 

MAND_SRCS   = push_swap.c \
              sort_stack.c \
	      sort_utils.c

BONUS_SRCS  = bonus/checker.c \
	      bonus/checker_utils.c \
              bonus/get_next_line/get_next_line.c \
              bonus/get_next_line/get_next_line_utils.c

MAND_OBJS   = $(SHARED_SRCS:.c=.o) $(MAND_SRCS:.c=.o)
BONUS_OBJS  = $(SHARED_SRCS:.c=.o) $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(MAND_OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(MAND_OBJS)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(BONUS_NAME) $(BONUS_OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(MAND_OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re
