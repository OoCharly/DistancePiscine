#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/01/05 21:10:18 by cdesvern          #+#    #+#             *#
#*   Updated: 2016/01/06 09:23:05 by cdesvern         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME = ft_cat
FLAGS = -Wall -Wextra -Werror
SRC = ft_cat.c
OBJ =

all: $(NAME)

$(NAME):
	clang $(FLAGS) $(SRC) -o $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
