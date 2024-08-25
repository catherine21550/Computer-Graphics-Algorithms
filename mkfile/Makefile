# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khuk <khuk@student.42vienna.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/08 17:25:51 by khuk              #+#    #+#              #
#    Updated: 2024/08/25 14:15:43 by khuk             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= fdf

SRCS= main.c fdf_count.c fdf_get_map.c fdf_mem_clean.c fdf_utils.c \
	fdf_draw_img.c fdf_init.c \


OBJS= $(SRCS:.c=.o)

MLXFLAGS= -lmlx_Linux -Lmlx_linux -lXext -lX11 -lm 

CFLAGS=  -Wall -Wextra -Werror

CC= cc

LIB= GNL/libftprintfgnl.a

all: $(NAME)

$(LIB):
	make -C GNL/ re

$(NAME): $(OBJS) $(LIB)
		$(CC) $(CFLAGS) $(OBJS) $(LIB) -L/usr/lib $(MLXFLAGS) -o $(NAME)

test: $(NAME1)


%.o: %.c
	cc -c $(CFLAGS) -I/usr/include -Imlx_linux -o $@ -c $<

clean:
	make clean -C GNL/
	rm -f $(OBJS)

fclean: clean
	make fclean -C GNL/
	rm -f $(NAME) 

re: fclean all

.PHONY: all clean fclean re
