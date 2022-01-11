# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: redarnet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/07 11:44:19 by redarnet          #+#    #+#              #
#    Updated: 2020/01/07 11:47:11 by redarnet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cub3D

CC = clang
FLAGS = -Wall -Wextra -Werror
MLX  = -lXext -lX11 -lm -lbsd minilibx-linux/libmlx_Linux.a 
LIBFT = ./libft

SRC  = src/algo.c \
 	src/algo2.c\
	src/checkmap.c\
	src/decor.c\
	src/convertisseur.c\
	src/draw_walls.c\
	src/erreur.c\
	src/free.c\
	src/ft_itoa_base.c\
	src/main.c\
	src/map.c\
	src/parsing2.c\
	src/parsing.c\
	src/raycasting.c\
	src/save.c\
	src/sprite.c\
	src/textures.c\
	src/utils.c\
	src/get_next_line/get_next_line.c\
	src/get_next_line/get_next_line_utils.c

OBJS = $(SRC:.c=.o)


all:  $(NAME) 


minilibx:

$(%.o): $(%.c)
	$(CC) -o $@  $^ 

$(NAME): $(OBJS)
	make -C libft
	make -C minilibx-linux/
	$(CC)  -o $@  $^  libft/libft.a $(MLX)   

clean: 
	make -C libft/ clean 
	make -C minilibx-linux/ clean 
	rm $(OBJS)
fclean: 
	make -C libft/ fclean 
	make -C minilibx-linux/ clean 
	rm $(OBJS)
	rm $(NAME)
re: fclean all
