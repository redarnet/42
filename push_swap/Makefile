


NAME = push_swap

CC = clang
FLAGS =  -Wextra -Werror
LIBFT = ./libft

SRC  = change_num.c\
	error.c\
	long_tri.c\
	main.c\
	operation2.c\
	operation.c\
	short_tri.c\
	utils.c\
	very_long_tri.c\
	string.c\
	algo.c

OBJS = $(SRC:.c=.o)


all:  $(NAME) 



$(NAME): $(OBJS)
	make -C libft
	$(CC)  -o $@  $^  libft/libft.a $(MLX)   

clean: 
	make -C libft/ clean 
	rm $(OBJS)
fclean: 
	make -C libft/ fclean 
	rm $(OBJS)
	rm $(NAME)
re: fclean all
