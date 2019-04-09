##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Creation of makefile
##

SRC	=	src/my_putchar.c		\
		src/my_putstr.c			\
		src/my_strcmp.c			\
		src/my_strlen.c			\
		src/my_strcat.c			\
		src/my_str_to_word_array.c	\
		src/exec.c			\
		src/minishell2.c		\
		src/builtins.c			\
		src/main.c

CC	=	gcc

CFLAGS	+=	-I./include/

LFLAGS	=	-g3 -Wall -Wextra

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

debug:
	$(CC) $(CFLAGS) $(LFLAGS) -o $(NAME) $(SRC)

clean:
	rm -f $(OBJ)
	rm -f *.gcno *.gcda

fclean:	clean
	rm -f $(NAME) $(TEST)

re:	fclean all

.PHONY:	debug clean fclean re
