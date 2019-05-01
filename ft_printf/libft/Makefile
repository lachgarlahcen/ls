# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llachgar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/06 19:17:09 by llachgar          #+#    #+#              #
#    Updated: 2018/10/06 20:38:19 by llachgar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

$(NAME):
	gcc -c -Wall -Wextra -Werror *.c
	ar rc $(NAME) *.o
all: $(NAME)

clean:
	rm -f *.o
fclean: clean
	rm -f *.a
re: fclean all
