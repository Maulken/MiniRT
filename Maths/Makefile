# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmassoli <vmassoli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/11 11:32:32 by mpelluet          #+#    #+#              #
#    Updated: 2024/08/15 12:08:25 by vmassoli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	camera\
		main\
		objects\
		ray_tracing\
		vector\
		colors\


INC_FILES = -Iminilibx

INC_ARCHIVES = minilibx/libmlx_Linux.a

LINKS = -L minilibx/ -lmlx -lXext -lX11

SRC = $(addsuffix .c,$(SRCS))
OBJ = $(addsuffix .o,$(SRCS))

CC = cc
CFLAGS = -Wall -Wextra -Werror -Ofast

NAME = minirt

all: $(NAME)

$(NAME) : $(OBJ)
	make -C minilibx
	$(CC) -o $@ $(OBJ) $(INC_ARCHIVES) $(LINKS) -lm

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS) $(INC_FILES)

bonus : all

clean :
	rm -rf $(OBJ) $(BOBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean
	make

.PHONY : all bonus clean fclean re
