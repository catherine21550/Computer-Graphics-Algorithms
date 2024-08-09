# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khuk <khuk@student.42vienna.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/08 17:25:51 by khuk              #+#    #+#              #
#    Updated: 2024/08/09 16:05:24 by khuk             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= fdf

SRCS= test.c

OBJS= $(SRCS:.c=.o)

MLXFLAGS= -lmlx -lXext -lX11

CFLAGS= -Wall -Wextra -Werror

CC= cc

LIB= GNL/libftprintfgnl.a

all: $(NAME)

$(LIB):
	make -C GNL/ re

$(NAME): $(OBJS) $(LIB)
		$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJS) $(LIB) -o $(NAME)

%.o: %.c
	cc -c $(CFLAGS) -Imlx -o $@ -c $<

clean:
	make clean -C GNL/
	rm -f $(OBJS)

fclean: clean
	make fclean -C GNL/
	rm -f $(NAME) 

re: fclean all

.PHONY: all clean fclean re
