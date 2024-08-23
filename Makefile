# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khuk <khuk@student.42vienna.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/08 17:25:51 by khuk              #+#    #+#              #
#    Updated: 2024/08/12 18:12:45 by khuk             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= fdf

SRCS= test.c fdf_count.c fdf_get_map.c fdf_mem_clean.c fdf_utils.c \
	fdf_draw_img.c \

OBJS= $(SRCS:.c=.o)

MLXFLAGS= -lmlx -lXext -lX11 -lm

CFLAGS= -g -Wall -Wextra -Werror

CC= cc 

LIB= GNL/libftprintfgnl.a

all: $(NAME)

$(LIB):
	make -C GNL/ re

$(NAME): $(OBJS) $(LIB)
		$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJS) $(LIB) -o $(NAME)

%.o: %.c
	cc -c $(CFLAGS) -Imlx -I$(LIB) -o $@ -c $<

clean:
	make clean -C GNL/
	rm -f $(OBJS)

fclean: clean
	make fclean -C GNL/
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
