NAME = ft_hexdump
FLAGS = -Wall -Wextra -Werror
SRC = ft_puterr.c ft_strcmp.c ft_calc.c ft_read_file.c ft_hexdump_print.c main.c
OBJ =

all: $(NAME)

$(NAME):
	clang $(FLAGS) $(SRC) -o $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
