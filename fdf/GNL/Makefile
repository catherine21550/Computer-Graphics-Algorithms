NAME = libftprintfgnl.a

SRC = get_next_line_bonus.c\
      get_next_line_utils_bonus.c\

OBJ = $(SRC:.c=.o)

CC = cc

HEAD = -I.

CFLAGS = -c -Wall -Wextra -Werror

LIBINC = -I printf/ft_printf.h -L./printf -lft

all: $(NAME)

$(NAME): $(OBJ)
	@make -C printf/ re --no-print-directory -s
	@cp printf/libftprintf.a $(NAME)
	@ar -q  $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ $<

clean:
	@rm -f $(OBJ)
	@make clean -C printf/ -s
	@make clean -C printf/libft/ -s

fclean: clean
	@rm -f $(NAME)
	@make fclean -C printf/ -s

re: fclean all

.PHONY: all clean fclean re
