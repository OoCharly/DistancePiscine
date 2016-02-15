# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/01 20:39:54 by cdesvern          #+#    #+#              #
#    Updated: 2015/11/01 20:45:16 by cdesvern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = colle-2

SRC =  ft_putchar.c ft_putnbr.c ft_putstr.c ft_strcmp.c  main.c\
	  ft_coordinate.c ft_pipe_to_string.c ft_test.c colle_2.c

FLAG = -Werror -Wall -Wextra

OPTS = -o

all: $(NAME)

$(NAME):
	gcc $(FLAG) $(SRC) $(OPTS) $(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all
