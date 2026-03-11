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

NAME    = fdf
SRCS    = srcs/main_bonus.c srcs/fdf_count_bonus.c srcs/fdf_get_map_bonus.c \
          srcs/fdf_mem_clean_bonus.c srcs/fdf_utils_bonus.c \
          srcs/fdf_handling_bonus.c srcs/fdf_draw_img_bonus.c \
          srcs/fdf_init_bonus.c srcs/fdf_shift_bonus.c \
          srcs/fdf_draw_img2_bonus.c

OBJS    = $(SRCS:.c=.o)
MLXFLAGS = -lmlx -lXext -lX11 -lm
CFLAGS   = -Wall -Wextra -Werror
CC       = cc
LIB      = GNL/libftprintfgnl.a

all: $(NAME)

$(LIB):
	@make -C GNL/ re --no-print-directory

$(NAME): $(OBJS) $(LIB)
	@$(CC) $(CFLAGS) $(OBJS) $(LIB) $(MLXFLAGS) -o $(NAME)
	@echo "✅ FdF compiled successfully!"

%.o: %.c
	@$(CC) $(CFLAGS) -Imlx -Ibonus -IGNL -c $< -o $@

clean:
	@make clean -C GNL/ --no-print-directory -s
	@rm -f $(OBJS)
	@echo "🧹 Objects removed."

fclean: clean
	@make fclean -C GNL/ --no-print-directory -s
	@rm -f $(NAME)
	@echo "🧼 Binaries removed."

re: fclean all

.PHONY: all clean fclean re
