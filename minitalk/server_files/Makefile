NAME = server

CC = clang
FLAGS =  -Wextra -Werror

SRC  = main.c

OBJS = $(SRC:.c=.o)



all:  $(NAME)


$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $@  $^     
	mv $(NAME) ../

clean: 
	rm -rf $(OBJS)
fclean:  
	rm -rf $(OBJS)
	
	rm -rf ../$(NAME)
re: fclean all
