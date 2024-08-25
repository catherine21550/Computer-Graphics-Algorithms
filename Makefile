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

SRCS= mandatory/main.c mandatory/fdf_count.c mandatory/fdf_get_map.c \
	mandatory/fdf_mem_clean.c mandatory/fdf_utils.c mandatory/fdf_handling.c \
	mandatory/fdf_draw_img.c mandatory/fdf_init.c mandatory/fdf_shift.c \

OBJS= $(SRCS:.c=.o)

MLXFLAGS= -lmlx -lXext -lX11 -lm

CFLAGS= -Wall -Wextra -Werror

CC= cc 

LIB= GNL/libftprintfgnl.a

all: $(NAME)

$(LIB):
	make -C GNL/ re

$(NAME): $(OBJS) $(LIB)
		$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJS) $(LIB) -o $(NAME)

%.o: %.c
	cc -c $(CFLAGS) -Imlx -Imandatory -I$(LIB) -o $@ -c $<

clean:
	make clean -C GNL/
	rm -f $(OBJS)

fclean: clean
	make fclean -C GNL/
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
