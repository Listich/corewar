##
## EPITECH PROJECT, 2022
## minishell1
## File description:
## Makefile
##

SRC = binary.c\
	  op.c\

OBJ	=	$(SRC:.c=.o)

NAME	= asm/asm

CFLAGS	=	-W -Wall -Wextra -I include/ -libmy

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ)

all: $(NAME)

clean:
	find . -name "*~" -delete -or -name "#*#" -delete
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re