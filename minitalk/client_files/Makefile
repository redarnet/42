NAME = client

CC = clang
FLAGS =  -Wextra -Werror

SRC  = client.c\
       client_utils.c

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
