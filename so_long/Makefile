


NAME = so_long

CC = clang
FLAGS =  -Wextra -Werror
MLX  = -lXext -lX11 -lm -lbsd minilibx-linux/libmlx_Linux.a 
LIBFT = ./libft

SRC  = src/draw_walls.c\
	src/error_free.c\
	src/main.c\
	src/parsing.c\
	src/textures.c\
	src/parsing2.c\
	src/algo.c\
	src/get_next_line/get_next_line.c\
	src/get_next_line/get_next_line_utils.c\
	src/get_next_line/ft_strjoin.c

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
