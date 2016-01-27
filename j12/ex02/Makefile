#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/01/12 20:23:22 by cdesvern          #+#    #+#             *#
#*   Updated: 2016/01/12 20:27:19 by cdesvern         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME = ft_tail
FLAGS = -Wall -Wextra -Werror
SRC = ft_tail.c ft_puterr.c ft_strcmp.c
OBJ =

all: $(NAME)

$(NAME):
	clang $(FLAGS) $(SRC) -o $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
