# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/11 10:58:17 by vmassoli          #+#    #+#              #
#    Updated: 2024/08/22 09:43:49 by vharatyk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	libft.a

# Source directories
SRC_DIR				=	./src
SRC_BONUS_DIR		=	$(SRC_DIR)/bonus
SRC_GNL_DIR			=	$(SRC_DIR)/get_next_line
SRC_PRINTF_DIR		=	$(SRC_DIR)/ft_printf
SRC_PRINTF_FD_DIR	=	$(SRC_DIR)/ft_printf_fd

# Other directories
OBJ_DIR				=	./obj
INCLUDE_DIR			=	./include
HEADERS				=	$(INCLUDE_DIR)/libft.h

# Compiler and flags
CC					=	cc
CFLAGS				=	-Wall -Wextra -Werror -I$(INCLUDE_DIR) -fPIC

# Archiver
AR					=	ar rcs

# Remove command
RM					=	rm -rf

# Source files
SRC					=	ft_atoi.c \
						ft_bzero.c \
						ft_calloc.c \
						ft_isalnum.c \
						ft_isalpha.c \
						ft_isascii.c \
						ft_isdigit.c \
						ft_isprint.c \
						ft_itoa.c \
						ft_memchr.c \
						ft_memcmp.c \
						ft_memcpy.c \
						ft_memmove.c \
						ft_memset.c \
						ft_putchar_fd.c \
						ft_putendl_fd.c \
						ft_putnbr_fd.c \
						ft_putstr_fd.c \
						ft_split.c \
						ft_strchr.c \
						ft_strdup.c \
						ft_striteri.c \
						ft_strjoin.c \
						ft_strlcat.c \
						ft_strlcpy.c \
						ft_strlen.c \
						ft_strmapi.c \
						ft_strncmp.c \
						ft_strnstr.c \
						ft_strrchr.c \
						ft_strtrim.c \
						ft_substr.c \
						ft_tolower.c \
						ft_toupper.c

SRC_OTHER			=	ft_arrlen.c \
						ft_free_str_arr_2d.c \
						ft_free_str_arr.c \
						ft_split_quotes_2d.c \
						ft_split_quotes.c \
						ft_strcmp.c \
						ft_strdup_arr.c \
						ft_strreplace.c

SRC_GNL				=	get_next_line.c

SRC_PRINTF			=	ft_printf_utils.c \
						ft_printf_utils2.c \
						ft_printf.c

SRC_PRINTF_FD		=	ft_printf_fd_utils.c \
						ft_printf_fd_utils2.c \
						ft_printf_fd.c

# Object files
OBJ					=	$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
OBJ_BONUS			=	$(addprefix $(OBJ_DIR)/, $(SRC_BONUS:.c=.o))
OBJ_OTHER			=	$(addprefix $(OBJ_DIR)/, $(SRC_OTHER:.c=.o))
OBJ_GNL				=	$(addprefix $(OBJ_DIR)/, $(SRC_GNL:.c=.o))
OBJ_PRINTF			=	$(addprefix $(OBJ_DIR)/, $(SRC_PRINTF:.c=.o))
OBJ_PRINTF_FD		=	$(addprefix $(OBJ_DIR)/, $(SRC_PRINTF_FD:.c=.o))
OBJ_FULL			=	$(OBJ) $(OBJ_BONUS) $(OBJ_OTHER) $(OBJ_GNL) $(OBJ_PRINTF) $(OBJ_PRINTF_FD)

# Compile individual source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS) | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_BONUS_DIR)/%.c $(HEADERS) | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_GNL_DIR)/%.c $(HEADERS) | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_PRINTF_DIR)/%.c $(HEADERS) | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_PRINTF_FD_DIR)/%.c $(HEADERS) | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

# Phony Targets
all: $(NAME)

clean:
	@$(RM) $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

$(NAME): $(OBJ_FULL)
	@$(AR) $(NAME) $(OBJ_FULL)

# Create object directory
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

.PHONY: all clean fclean re
