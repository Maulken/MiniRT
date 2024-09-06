# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmassoli <vmassoli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/30 13:30:15 by vmassoli          #+#    #+#              #
#    Updated: 2024/09/04 14:09:43 by vmassoli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC      = gcc
CFLAGS  = -g -Wall -Wextra -Werror
CLINKS  = -lXext -lX11 -lm

### EXECUTABLE ###
NAME   = minirt

### PATH ###
HEADER_PATH		= includes/minirt.h libft/includes/libt.h includes/scene.h
SRC_PATH 		= sources
MLX				= minilibx-linux
LIBMLX			= $(MLX)/libmlx.a
LIBFT			= libft/libft.a
LFLAGS			= -L libft -lft -fPIC

### SOURCE FILES ###
SOURCES = main.c \
 init.c \
 clear.c \
 parsing/check_object_essential.c \
 parsing/check_object_liste.c \
 parsing/check_object.c \
 parsing/check_type.c \
 parsing/check_utils.c \
 parsing/check.c \
 parsing/conversion.c \
 parsing/ft_atof.c \
 parsing/get_file.c \
 parsing/parsing.c \
 parsing/split_space.c \
 parsing/utils.c \
 parsing/utils2.c \
 rt/colors.c \
 rt/cylinder.c \
 rt/cylinder2.c \
 rt/maths_util.c \
 rt/plane.c \
 rt/ray_tracing.c \
 rt/sphere.c\
 rt/vector.c \
 rt/vector2.c \

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
