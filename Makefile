# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khuk <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/07 17:20:42 by khuk              #+#    #+#              #
#    Updated: 2024/08/07 21:16:42 by khuk             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= fdf

SRCS= 

OBJS= $(SRCS: .c=.o)

CFLAGS= -Wall -Wextra -Werror

CC= cc

LIB= 

all: $(NAME)

$(LIB):

$(NAME): $(OBJS) $(LIB)
		$(CC) $(CFLAGS) $(OBJ1) $(LIB) -o $(NAME1)

%.o: %.c
	mkdir 
	cc $(CFLAGS) -o $@ -c $<

clean:
	make clean -C printf/
	rm -f $(OBJ1) $(OBJ2) $(OBJ3) $(OBJ4)

fclean: clean
	make fclean -C printf/
	rm -f $(NAME1) $(NAME2) $(NAME1_BONUS) $(NAME2_BONUS)

re: fclean all bonus

.PHONY: all bonus clean fclean re
