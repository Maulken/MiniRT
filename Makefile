# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/30 13:30:15 by vmassoli          #+#    #+#              #
#    Updated: 2024/08/15 10:39:09 by vharatyk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC      = cc
CFLAGS  = ##-Wall  -Wextra -Werror -g
CLINKS  = -lXext -lX11 -lm

### EXECUTABLE ###
NAME   = MiniRT

### PATH ###
HEADER_PATH		= includes/minirt.h libft/includes/libt.h includes/scene.h
SRC_PATH 		= sources
MLX				= minilibx-linux
LIBMLX			= $(MLX)/libmlx.a
LIBFT			= libft/libft.a
LFLAGS			= -L libft -lft -lreadline -lm

### SOURCE FILES ###
SOURCES = main.c \
 rt/init.c rt/clear.c \
 parsing/parsing.c  parsing/check.c  parsing/get_file.c  parsing/utils.c parsing/conversion.c parsing/check_object.c parsing/check_object2.c parsing/check_type.c parsing/check_utils.c

### OBJECTS ###

SRCS = $(addprefix $(SRC_PATH)/,$(SOURCES))

OBJS = $(SRCS:.c=.o)


### RULES ###
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)  $(LIBFT) $(LIBMLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBMLX) -o $(NAME) $(CLINKS) $(LFLAGS)

$(LIBMLX):
	make -C $(MLX)

$(LIBFT): libft
	cd libft && $(MAKE)

clean:
	cd libft && $(MAKE) --quiet clean
	$(RM) $(OBJS)

fclean: clean
	cd libft && $(MAKE) --quiet fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: re, fclean, clean
