NAME = philo

CC = clang
FLAGS = -Wall -Wextra -Werror 

SRC  =   main.c\
		thread.c\
        utils.c\
		time.c\
		fork.c\
		clear.c

OBJS = $(SRC:.c=.o)



%.o:	%.c
		$(CC) $(FLAGS) -c $< -o $@

all:  $(NAME)

$(NAME): $(OBJS)
	 $(CC)  $(FLAGS) -o  $@  $^ -pthread  
	 

clean: 
	rm -rf $(OBJS)
fclean: 
	rm -rf $(OBJS)
	rm -rf $(NAME)
re: fclean all
