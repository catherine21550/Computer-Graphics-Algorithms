# -------------------------------------------------------------------
# VARIABLES
# -------------------------------------------------------------------

# Source file directories
SRCS_DIR			= ./srcs/
#PARSING_DIR			= ./srcs/parsing/
#RAYCAST_DIR			= ./srcs/raycasting/

# Other directories
OBJS_DIR			= ./objs/
LIBFT_DIR			= ./libft/
INCLUDES_DIR			= ./includes/

# Source files
CFILES_ROOT			= main.c \

#CFILES_PARCING			= \

#CFILES_RAYCAST			= \

OBJ_FILES 			:= $(CFILES_ROOT:.c=.o) \
#			  	   $(CFILES_PARCING:.c=.o) \
#			  	   $(CFILES_RAYCAST:.c=.o) \

OBJS				:= $(addprefix $(OBJS_DIR), $(OBJ_FILES))

# Compilation variables
NAME				= cub3D
CC 				= cc
CFLAGS 				= -g -Wall -Werror -Wextra
RM 				= rm -rf
LINKFLAGS			:= -L$(LIBFT_DIR) -lft -lreadline
INCLUDES			:= -I$(INCLUDES_DIR) -I$(LIBFT_DIR)
LIBFT				:= $(addprefix $(LIBFT_DIR), libft.a)

# -------------------------------------------------------------------
# RULES
# -------------------------------------------------------------------

all: $(NAME)

$(NAME): $(OBJS)
	@make all -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LINKFLAGS)

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
	$(CC) $(CFLAGS) -c $< $(INCLUDES) -o $@

#$(OBJS_DIR)%.o: $(PARSING_DIR)%.c
#	@mkdir -p $(OBJS_DIR)
#	$(CC) $(CFLAGS) -c $< $(INCLUDES) -o $@
	
#$(OBJS_DIR)%.o: $(RAYCAST_DIR)%.c
#	@mkdir -p $(OBJS_DIR)
#	$(CC) $(CFLAGS) -c $< $(INCLUDES) -o $@
