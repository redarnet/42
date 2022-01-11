NAME = SERVER
NAME2 = CLIENT

FILE_SERVER = ./server_files
FILE_CLIENT = ./client_files

all : $(NAME) $(NAME2)

$(NAME) :
		make -C server_files/ all 
$(NAME2) :
		make -C client_files/ all 

clean :
	make -C server_files/ clean
	make -C client_files/ clean

fclean:	
	make -C server_files/ fclean
	make -C client_files/ fclean

re: fclean all
