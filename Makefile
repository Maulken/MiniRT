# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpelluet <mpelluet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/30 13:30:15 by vmassoli          #+#    #+#              #
#    Updated: 2024/09/06 13:16:13 by mpelluet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC      = gcc
CFLAGS  = -g -Wall -Wextra -Werror
CLINKS  = -lXext -lX11 -lm 

### EXECUTABLE ###
NAME   = minirt

### PATH ###
HEADER_PATH		= includes/minirt.h libft/includes/libt.h includes/scene.h 
PATH_MAIN 		= sources
PATH_PARCING 	= sources/parsing
PATH_RT 		= sources/rt
MLX				= minilibx-linux
LIBMLX			= $(MLX)/libmlx.a
LIBFT			= libft/libft.a
LFLAGS			= -L libft -lft -fPIC

### SOURCE FILES ###
SOURCES_MAIN = main.c init.c init_scene.c init_object.c clear.c clear_object.c clear_object2.c clear_scene.c
SOURCES_PARSING = parsing.c check.c get_file.c  utils.c \
conversion.c check_object.c check_object_essential.c check_object_liste.c \
check_type.c check_utils.c ft_atof.c utils2.c split_space.c 
SOURCES_RT = ray_tracing.c vector.c vector2.c colors.c maths_util.c sphere.c

SOURCES_PATH_MAIN= $(addprefix $(PATH_MAIN)/,$(SOURCES_MAIN))
SOURCES_PATH_PARSING = $(addprefix $(PATH_PARCING)/,$(SOURCES_PARSING))
SOURCES_PATH_RT = $(addprefix $(PATH_RT)/,$(SOURCES_RT))

SOURCES = $(SOURCES_PATH_MAIN) $(SOURCES_PATH_PARSING) $(SOURCES_PATH_RT)
### OBJECTS ###
SRCS = $(SOURCES)

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
