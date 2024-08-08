# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmassoli <vmassoli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/30 13:30:15 by vmassoli          #+#    #+#              #
#    Updated: 2024/08/02 12:09:45 by vmassoli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	minirt

SRC_DIR				=	src

LIBFT_DIR			=	libft
LIBFT				=	$(LIBFT_DIR)/libft.a

# Other directories
OBJ_DIR				=	obj
INCLUDE_DIR			=	include
#SCENES_DIR			=	scenes
#PARSE_EXECUTE_DIR	=	parse_execute
#BUILTINS_DIR		=	builtins
HEADERS				=	$(INCLUDE_DIR)/minirt.h \
						$(LIBFT_DIR)/include/libft.h

# Compiler and flags
CC = cc
CFLAGS				=	-Wall -Wextra -Werror -I$(INCLUDE_DIR) -I$(LIBFT_DIR)/include
LFLAGS				=	-L$(LIBFT_DIR) -lft -lreadline

# Remove command
RM					=	rm -rf

# Source files
SRC 				=	main.c

# Object files
OBJ					=	$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

# Compile individual source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS) | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

# Phony targets
all: $(NAME)

clean:
	@cd $(LIBFT_DIR) && $(MAKE) --quiet clean
	@$(RM) $(OBJ_DIR)

fclean: clean
	@cd $(LIBFT_DIR) && $(MAKE) --quiet fclean
	@$(RM) $(NAME)


re: fclean all

# Target rules
$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LFLAGS)

# Create directories for object files
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Library compilation
$(LIBFT): $(LIBFT_DIR)
	@cd $(LIBFT_DIR) && $(MAKE)


.PHONY: all clean fclean re
