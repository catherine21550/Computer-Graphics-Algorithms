# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khuk <khuk@student.42vienna.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/08 17:25:51 by khuk              #+#    #+#              #
#    Updated: 2024/08/08 17:42:35 by khuk             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= fdf

SRCS= test.c

OBJS= $(SRCS: .c=.o)

MLXFLAGS= -lmlx -lXext -lX11

CFLAGS= -Wall -Wextra -Werror

CC= cc

LIB= GNL/libftprintfgnl.a

all: $(NAME)

$(LIB):

$(NAME): $(OBJS) $(LIB)
		$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJ1) $(LIB) -o $(NAME1)

%.o: %.c
	mkdir objs
	cd objs
	cc $(CFLAGS) $(MLXFLAGS) -o $@ -c ../$<

clean:
	make clean -C printf/
	rm -f $(OBJ1) $(OBJ2) $(OBJ3) $(OBJ4)

fclean: clean
	make fclean -C printf/
	rm -f $(NAME1) $(NAME2) $(NAME1_BONUS) $(NAME2_BONUS)

re: fclean all

.PHONY: all clean fclean re
