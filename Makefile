# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/14 00:58:22 by ryoshio-          #+#    #+#              #
#    Updated: 2022/04/30 10:10:53 by ryoshio-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
CC = clang
CFLAG = -Wall -Werror -Wextra -v

LIBFT = libft/libft.a




$(NAME): all

all:
	make -C libft
	$(CC) $(CFLAG) -o server server.c  $(LIBFT) 
	$(CC) $(CFLAG) -o client client.c  $(LIBFT) 

clean:
	make clean -C libft
	rm -rf server.o client.o 

fclean:
	make fclean -C libft 
	rm -rf server client 


re: fclean all

.PHONY: all re flean clean  

