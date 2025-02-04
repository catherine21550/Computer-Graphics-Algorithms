# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khuk <khuk@student.42vienna.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/04 15:02:26 by khuk              #+#    #+#              #
#    Updated: 2025/02/04 15:45:34 by khuk             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -------------------------------------------------------------------
# VARIABLES
# -------------------------------------------------------------------

# Source file directories
SRCS_DIR			= ./srcs/
PARSING_DIR			= ./srcs/parsing/
GRAPHIC_DIR			= ./srcs/graphic/

# Other directories
OBJS_DIR			= ./objs/
LIBFT_DIR			= ./libft/
INCLUDES_DIR		= ./includes/

# Source files
CFILES_ROOT			= main.c \

CFILES_PARCING		= parse_data.c \
					  store_content.c \
					  map_checking.c \
					  parse_utils.c \
					  visual_info.c \

CFILES_GRAPHIC			= \

OBJ_FILES 			:= $(CFILES_ROOT:.c=.o) \
			  		   $(CFILES_PARCING:.c=.o) \
			  		   $(CFILES_GRAPHIC:.c=.o)

OBJS				:= $(addprefix $(OBJS_DIR), $(OBJ_FILES))

# Compilation variables
NAME				= cub3D
CC 					= cc
CFLAGS 				= -g -Wall -Werror -Wextra
MLXFLAGS			= -lmlx -lXext -lX11 -lm
RM 					= rm -rf
LINKFLAGS			:= -L$(LIBFT_DIR) -lft -lreadline
INCLUDES			:= -I$(INCLUDES_DIR) -I$(LIBFT_DIR)
LIBFT				:= $(addprefix $(LIBFT_DIR), libft.a)

# -------------------------------------------------------------------
# RULES
# -------------------------------------------------------------------

all: $(NAME)

$(NAME): $(OBJS)
	@make all -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(MLXFLAGS) -o $(NAME) $(OBJS) $(LINKFLAGS)

clean:
	@make clean -C $(LIBFT_DIR)
	$(RM) objs

fclean: clean
	$(RM) $(LIBFT)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

# -------------------------------------------------------------------
# OBJECT RULES
# -------------------------------------------------------------------
# // These have to be implemented for each directory in the project

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) $(MLXFLAGS) -c $< $(INCLUDES) -o $@

$(OBJS_DIR)%.o: $(PARSING_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) $(MLXFLAGS) -c $< $(INCLUDES) -o $@
	
$(OBJS_DIR)%.o: $(GRAPHIC_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) $(MLXFLAGS) -c $< $(INCLUDES) -o $@
