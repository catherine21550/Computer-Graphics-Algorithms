NAME = libftprintfgnl.a

SRC = get_next_line_bonus.c\
      get_next_line_utils_bonus.c\

OBJ = $(SRC:.c=.o)

HEAD = -I.

CFLAGS = -c -Wall -Wextra -Werror

LIBINC = -I printf/ft_printf.h -L./printf -lft

all: $(NAME)

$(NAME): $(OBJ)
	make -C printf/ re
	cp printf/libftprintf.a $(NAME)
	ar -q  $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	cc $(CFLAGS) -o $@ $<

clean:
	rm -f $(OBJ)
	make clean -C printf/
	make clean -C printf/libft/

fclean: clean
	rm -f $(NAME)
	make fclean -C printf/

re: fclean all

.PHONY: all clean fclean re
