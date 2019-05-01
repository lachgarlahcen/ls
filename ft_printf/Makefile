# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llachgar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/01 22:43:43 by llachgar          #+#    #+#              #
#    Updated: 2019/01/31 14:27:45 by llachgar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

$(NAME):
	@gcc -c -Wall -Werror -Wextra *.c libft/*.c
	@ar rc $(NAME) *.o
	@ranlib $(NAME)

all: $(NAME)

clean:
	@make clean -C libft
	@rm -f *.o
fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)
re: fclean | all
