# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykarabul <@student.42kocaeli.com.tr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/18 20:53:13 by ykarabul          #+#    #+#              #
#    Updated: 2023/03/02 13:10:52 by ykarabul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror -I./minilibx -g
LFLAGS = -framework AppKit -framework OpenGL -L./minilibx -lmlx
MLX = ./minilibx/libmlx.a
LIBFT = -I./libft
PRINTF = -I./printf
GNL = $(wildcard gnl/*c)
GNLOBJS = $(GNL:.c=.o)
SRCS = main.c	controls1.c	controls2.c	controls3.c	controls4.c maps.c walk.c path_finder.c
OBJS = $(SRCS:.c=.o)
NAME = so_long

all : $(MLX) $(NAME)

$(MLX) :
	make bonus -sC LIBFT
	make -sC PRINTF
	make -sC ./minilibx

$(NAME) : $(OBJS) $(GNLOBJS)
	gcc $(OBJS) $(GNLOBJS) $(LFLAGS) ./libft/libft.a ./printf/libftprintf.a -o $(NAME)

clean:
	rm -rf $(OBJS) $(NAME)

fclean:
	rm -rf $(OBJS) $(NAME)
	rm -rf ./gnl/*.o
	make clean -C ./minilibx
	make fclean -C ./libft
	make fclean -C ./printf

norm:
	norminette ./*.c

re : fclean all

.PHONY: clean fclean re
