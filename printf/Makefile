# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: redarnet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/06 13:01:50 by redarnet          #+#    #+#              #
#    Updated: 2019/11/14 14:44:12 by redarnet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_strjoin.c ft_string.c ft_affiche_adresse.c ft_count.c ft_format.c ft_format_point.c ft_itoa.c ft_itoa_base.c ft_printf.c ft_putchar.c  ft_putstr.c ft_strdup.c 
FLAGS = -Wall -Wextra -Werror
O_FILE =  ft_strjoin.o ft_string.o ft_affiche_adresse.o ft_count.o ft_format.o ft_format_point.o ft_itoa.o ft_itoa_base.o ft_printf.o ft_putchar.o  ft_putstr.o ft_strdup.o

%.o : %.c 
	gcc $(FLAGS) -o $@ -c $< -I
all : $(NAME)

$(NAME) : $(O_FILE)
	ar rc libftprintf.a $(O_FILE)
clean :
	/bin/rm -f $(O_FILE)
fclean : clean
	/bin/rm -f $(NAME)
re : fclean all


