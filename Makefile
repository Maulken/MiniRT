# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/30 13:30:15 by vmassoli          #+#    #+#              #
#    Updated: 2024/08/08 08:59:31 by vharatyk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC      = cc
CFLAGS  = ##-Wall  -Wextra -Werror -g
CLINKS  = -lXext -lX11 -lm

### EXECUTABLE ###
NAME   = MiniRT

### PATH ###
HEADER_PATH = includes
SRC_PATH  = sources
MLX = minilibx-linux
LIBMLX = $(MLX)/libmlx.a

### SOURCE FILES ###
SOURCES = main.c rt/init.c rt/clear.c parsing/parsing.c

### OBJECTS ###

SRCS = $(addprefix $(SRC_PATH)/,$(SOURCES))
OBJS = $(SRCS:.c=.o)


### RULES ###

all: $(NAME)

$(NAME): $(OBJS) $(LIBMLX)
	$(CC) $(CFLAGS) -o $@ $^ $(CLINKS)

$(LIBMLX):
	make -C $(MLX)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: re, fclean, clean

