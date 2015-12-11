# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/02 20:49:30 by cdesvern          #+#    #+#              #
#    Updated: 2015/11/03 18:06:50 by cdesvern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_advanced_do-op
FLAGS = -Wall -Wextra -Werror
OPTS = -o $(NAME)
SRC = ft_putchar.c ft_putstr.c ft_ops.c ft_putnbr.c ft_main.c ft_atoi.c ft_strcmp.c
OBJ =

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) $(SRC) $(OPTS)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
