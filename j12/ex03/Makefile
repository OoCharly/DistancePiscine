#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/01/27 17:37:13 by cdesvern          #+#    #+#             *#
#*   Updated: 2016/01/27 17:40:02 by cdesvern         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME = ft_hexdump
FLAGS = -Wall -Wextra -Werror
SRC = ft_hexdump.c ft_puterr.c ft_strcmp.c ft_calc.c ft_print_hex.c main.c
OBJ =

all: $(NAME)

$(NAME):
	clang $(FLAGS) $(SRC) -o $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
