NAME = push_swap

SRC = main.c \
	ft_fill_info.c ft_push.c ft_sort_big.c ft_swap.c ft_rotate_ontop.c \
	ft_checkifvalid.c ft_find_min.c ft_rev_rotate.c ft_sort_in_two.c \
	ft_utils.c ft_create_stack.c ft_free.c ft_rotate.c ft_sort_small.c \
	
LIB = printf/libftprintf.a

CFLAGS = -Wall -Wextra -Werror

CC = cc

all: $(NAME)

$(NAME): $(SRC)
	@make -C printf/ re --silent --no-print-directory
	@$(CC) $(CFLAGS) $(SRC) $(LIB) -L printf/ -o push_swap
	@echo "Creating a program..."
	@echo "Program successfully compiled!"

%.o: %.c
	@$(CC) $(CFLAGS) $(LIB) -c $< -o $@

clean:
	@make clean -C printf/ --no-print-directory

fclean: clean
	@make fclean -C printf/ --no-print-directory
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
