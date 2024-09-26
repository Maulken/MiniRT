# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmassoli <vmassoli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/30 13:30:15 by vmassoli          #+#    #+#              #
#    Updated: 2024/09/26 11:33:29 by vmassoli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -O2 -g
CLINKS	= -lXext -lX11 -lm

### EXECUTABLE ###
NAME	= minirt

### PATH ###
HEADER_PATH		= includes/minirt.h libft/includes/libt.h includes/scene.h
PATH_MAIN		= sources
PATH_PARCING 	= sources/parsing
PATH_RT			= sources/rt
MLX				= minilibx-linux
LIBMLX			= $(MLX)/libmlx.a
LIBFT			= libft/libft.a
LFLAGS			= -L libft -lft -fPIC

### SOURCE FILES ###
SOURCES_MAIN =		main.c \
					init.c \
					init_scene.c \
					init_object.c \
					clear.c \
					clear_object.c \
					clear_scene.c
SOURCES_PARSING =	check_object_essential.c \
					check_object_liste.c \
					check_object.c \
					check_type.c \
					check_utils.c \
					check.c \
					conversion.c \
					get_file.c \
					parsing.c \
					split_space.c \
					utils.c \
					utils2.c
SOURCES_RT =		colors.c \
					cylinder.c \
					cylinder2.c \
					light.c\
					maths_util.c \
					plane.c \
					ray_tracing.c \
					sphere.c\
					vector.c \
					vector2.c \

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
