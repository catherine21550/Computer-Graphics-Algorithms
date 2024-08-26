# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khuk <khuk@student.42vienna.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/08 17:25:51 by khuk              #+#    #+#              #
#    Updated: 2024/08/26 23:39:13 by khuk             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= fdf

B_NAME= fdf_bonus

SRCS= mandatory/main.c mandatory/fdf_count.c mandatory/fdf_get_map.c \
	mandatory/fdf_mem_clean.c mandatory/fdf_utils.c mandatory/fdf_handling.c \
	mandatory/fdf_draw_img.c mandatory/fdf_init.c mandatory/fdf_shift.c \

B_SRCS= bonus/main_bonus.c bonus/fdf_count_bonus.c bonus/fdf_get_map_bonus.c \
        bonus/fdf_mem_clean_bonus.c bonus/fdf_utils_bonus.c \
        bonus/fdf_handling_bonus.c bonus/fdf_draw_img_bonus.c \
        bonus/fdf_init_bonus.c bonus/fdf_shift_bonus.c \
        bonus/fdf_draw_img2_bonus.c \

B_OBJS= $(B_SRCS:.c=.o)

OBJS= $(SRCS:.c=.o)

MLXFLAGS= -lmlx -lXext -lX11 -lm

CFLAGS= -Wall -Wextra -Werror

CC= cc 

LIB= GNL/libftprintfgnl.a

all: $(NAME)

bonus: $(B_NAME)

$(LIB):
	make -C GNL/ re

$(NAME): $(OBJS) $(LIB)
		@ $(CC) $(CFLAGS) $(MLXFLAGS) $(OBJS) $(LIB) -o $(NAME)

$(B_NAME): $(B_OBJS) $(LIB)
                $(CC) $(B_OBJS) $(CFLAGS) $(MLXFLAGS) $(LIB) -o $(B_NAME)

%.o: %.c
	@ cc -c $(CFLAGS) -Imlx -Imandatory -I$(LIB) -o $@ -c $<

clean:
	make clean -C GNL/
	rm -f $(OBJS) $(B_OBJS)

fclean: clean
	make fclean -C GNL/
	rm -f $(NAME) $(B_NAME)

re: fclean all

.PHONY: all bonus clean fclean re
