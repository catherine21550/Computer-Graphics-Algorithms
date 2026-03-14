NAME = libftprintf.a

SRC = ft_check_specifiers.c \
  ft_printf.c \
  ft_printchar.c \
  ft_printhex.c \
  ft_printhexbig.c \
  ft_printnbr.c \
  ft_print_ptr.c \
  ft_printstr.c \
  ft_printunbr.c

OBJ = $(SRC:.c=.o)

HEAD = -I.

CFLAGS = -c -Wall -Wextra -Werror

LIBINC = -I libft/libft.h -L./libft -lft

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/ re
	@cp libft/libft.a $(NAME)
	@ar -q  $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o: %.c
	@cc $(CFLAGS) -o $@ $<

clean:
	@rm -f $(OBJ)
	@make clean -C libft/

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft/

re: fclean all

.PHONY: all clean fclean re
