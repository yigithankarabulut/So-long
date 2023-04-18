# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykarabul <@student.42kocaeli.com.tr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/24 02:51:02 by ykarabul          #+#    #+#              #
#    Updated: 2022/12/24 02:51:02 by ykarabul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAG = -Wall -Wextra -Werror
SRC = $(shell find . -name "ft_*.c")

all: $(NAME)

$(NAME):
	gcc $(FLAG) -c $(SRC)
	ar rc $(NAME) *.o
clean:
	/bin/rm -f  *.o
fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re