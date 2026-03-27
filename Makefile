
NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

LIBFTDIR = libft

SRCS = push_swap.c \
	lst_utils.c \
	check_av.c \
	lst_utils2.c \
	fill_stack.c \
	sort.c \
	operations.c \
	operations2.c \
	sort_utils.c \
	cheapest_move.c
	
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFTDIR)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFTDIR) -lft -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re