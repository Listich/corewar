##
## EPITECH PROJECT, 2022
## info_file.c
## File description:
## Makefile
##

SRC = 	my_printf.c\
		my_put_nbr.c\
		my_putchar.c\
		my_putstr.c\
		my_revstr.c\
		my_strlen.c\
		non_printable.c\
		my_put_base.c\
		my_put_long.c\
		my_put_unsiegned.c\
		sign_manager.c

NAME = ../libmy.a

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

all: $(NAME)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all
