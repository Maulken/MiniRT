# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmassoli <vmassoli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/30 13:30:15 by vmassoli          #+#    #+#              #
#    Updated: 2024/08/17 14:22:26 by vmassoli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	minirt

SRC_DIR				=	src

LIBFT_DIR			=	libft
LIBFT				=	$(LIBFT_DIR)/libft.a
MLX_DIR				=	minilibx-linux
MINILIBX			=	$(MLX_DIR)/libmlx.a\

# Other directories
OBJ_DIR				=	obj
INCLUDE_DIR			=	includes
#SCENES_DIR			=	scenes
PARSING_DIR			=	parsing
RT_DIR				=	rt
HEADERS				=	$(INCLUDE_DIR)/minirt.h scene.h arena_internal.h\
						$(LIBFT_DIR)/include/libft.h \
						$(MLX_DIR)/libmlx.h libmlx_linux.h\

# Compiler and flags
CC = cc
CFLAGS				=	-Wall -Wextra -Werror -I$(INCLUDE_DIR) -I$(LIBFT_DIR)/include -I$(MLX_DIR) -g3
CLFLAGS				=	-lXext -lX11 -lm -L$(LIBFT_DIR) -lft -lreadline

# Remove command
RM					=	rm -rf

# Source files
SRC_PARSING			=	check_object.c \
						check_object2.c \
						check_type.c \
						check_utils.c \
						check.c \
						conversion.c \
						get_file.c \
						parsing.c \
						utils.c

SRC_RT				=	colors.c \
						objects.c \
						ray_tracing.c \
						rt.c \
						vector.c

SRC 				=	$(addprefix $(PARSING_DIR)/, $(SRC_PARSING)) \
						$(addprefix $(RT_DIR)/, $(SRC_RT)) \
						clear.c \
						init.c \
						main.c

# Object files
OBJ					=	$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

# Compile individual source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS) | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

# Phony targets
all: $(NAME)

clean:
	@cd $(LIBFT_DIR) && $(MAKE) --quiet clean
	@cd $(MLX_DIR) && $(MAKE) --quiet clean
	@$(RM) $(OBJ_DIR)

fclean: clean
	@cd $(LIBFT_DIR) && $(MAKE) --quiet fclean
	@cd $(MLX_DIR) && $(MAKE) --quiet clean
	@$(RM) $(NAME)


re: fclean all

# Target rules
$(NAME): $(LIBFT) $(OBJ) $(MINILIBX)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(CLFLAGS)

# Create directories for object files
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/$(PARSING_DIR)
	@mkdir -p $(OBJ_DIR)/$(RT_DIR)

# Library compilation
$(LIBFT): $(LIBFT_DIR)
	@cd $(LIBFT_DIR) && $(MAKE)


.PHONY: all clean fclean re
