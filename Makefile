# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmassoli <vmassoli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/11 10:21:16 by vmassoli          #+#    #+#              #
#    Updated: 2024/08/17 12:20:19 by vmassoli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	minishell

SRC_DIR				=	src

LIBFT_DIR			=	libft
LIBFT				=	$(LIBFT_DIR)/libft.a

# Other directories
OBJ_DIR				=	obj
INCLUDE_DIR			=	include
CHECK_INPUT_DIR		=	check_input
PARSE_EXECUTE_DIR	=	parse_execute
BUILTINS_DIR		=	builtins
HEADERS				=	$(INCLUDE_DIR)/minishell.h \
						$(LIBFT_DIR)/include/libft.h

# Compiler and flags
CC = cc
CFLAGS				=	-Wall -Wextra -Werror -I$(INCLUDE_DIR) -I$(LIBFT_DIR)/include
LFLAGS				=	-L$(LIBFT_DIR) -lft -lreadline

# Remove command
RM					=	rm -rf

# Source files
SRC_CHECK_INPUT		=	check_line.c \
						exit_status.c \
						quotes.c \
						redirections_space.c \
						replace_env_vars_2.c \
						replace_env_vars.c

SRC_PARSE_EXECUTE	=	child_process.c \
						cmd_data_path.c \
						cmd_data.c \
						cmd_in_out.c \
						cmd_input.c \
						cmd_output.c \
						execute.c \
						handle_commands.c \
						init_2.c \
						parse_execute.c \
						pid.c

SRC_BUILTINS		=	builtin_utils_2.c \
						builtin_utils.c \
						cd.c \
						echo.c \
						env.c \
						exit.c \
						export.c \
						pwd.c \
						unset.c

SRC 				=	$(addprefix $(CHECK_INPUT_DIR)/, $(SRC_CHECK_INPUT)) \
						$(addprefix $(PARSE_EXECUTE_DIR)/, $(SRC_PARSE_EXECUTE)) \
						$(addprefix $(BUILTINS_DIR)/, $(SRC_BUILTINS)) \
						clean_up_2.c \
						clean_up.c \
						err_msg.c \
						init.c \
						main.c \
						signals.c \
						utils.c

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
	@mkdir -p $(OBJ_DIR)/$(CHECK_INPUT_DIR)
	@mkdir -p $(OBJ_DIR)/$(PARSE_EXECUTE_DIR)
	@mkdir -p $(OBJ_DIR)/$(BUILTINS_DIR)

# Library compilation
$(LIBFT): $(LIBFT_DIR)
	@cd $(LIBFT_DIR) && $(MAKE)


.PHONY: all clean fclean re
