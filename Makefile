# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpelluet <mpelluet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/30 13:30:15 by vmassoli          #+#    #+#              #
#    Updated: 2024/08/22 10:28:10 by mpelluet         ###   ########.fr        #
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
LFLAGS			= -L libft -lft -lreadline -fPIC

### SOURCE FILES ###
SOURCES = main.c \
 init.c clear.c \
 parsing/parsing.c  parsing/check.c  parsing/get_file.c  parsing/utils.c parsing/conversion.c parsing/check_object.c parsing/check_object2.c parsing/check_type.c parsing/check_utils.c parsing/ft_atof.c parsing/utils2.c parsing/split_space.c \
 rt/ray_tracing.c rt/vector.c rt/vector2.c rt/colors.c rt/maths_util.c rt/sphere.c
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
