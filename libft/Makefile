# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: redarnet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/07 11:55:54 by redarnet          #+#    #+#              #
#    Updated: 2019/10/24 16:52:22 by redarnet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c ft_atoi.c ft_strlen.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_strdup.c ft_strnstr.c ft_strncmp.c ft_strrchr.c ft_strchr.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_strjoin.c ft_strtrim.c ft_itoa.c ft_calloc.c ft_memmove.c ft_strmapi.c ft_substr.c ft_strlcat.c ft_split.c ft_strlcpy.c
FlAGS = -Wall -Wextra -Werror
O_FILE = ft_putchar_fd.o ft_putstr_fd.o ft_putnbr_fd.o ft_putendl_fd.o ft_atoi.o ft_strlen.o ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o ft_toupper.o ft_tolower.o ft_strnstr.o ft_strdup.o ft_strncmp.o ft_strrchr.o ft_strchr.o ft_memset.o ft_bzero.o ft_memcpy.o ft_memccpy.o ft_memchr.o ft_memcmp.o ft_strjoin.o ft_strtrim.o  ft_itoa.o ft_calloc.o ft_memmove.o ft_strmapi.o ft_substr.o ft_strlcat.o ft_split.o ft_strlcpy.o  

%.o : %.c 
	gcc $(FLAGS) -o $@ -c $< -I 

all : $(NAME)

$(NAME): $(O_FILE)
		ar rc libft.a $(O_FILE)

clean: 
				/bin/rm -f $(O_FILE)
fclean: clean
				/bin/rm -f $(NAME)
re : fclean all
