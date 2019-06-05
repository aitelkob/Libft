# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/31 09:42:17 by yait-el-          #+#    #+#              #
#    Updated: 2019/04/03 01:17:51 by yait-el-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

INCLUDES = libft.h
FLAGS = -Wall -Wextra -Werror 


all : $(NAME)

$(NAME) :
	$(CC) $(FLAGS)  -c  *c -I $(INCLUDES)
			ar rc $(NAME) *.o

clean : 
		rm -f *.o

fclean : clean
		rm -f $(NAME)

re : fclean all

