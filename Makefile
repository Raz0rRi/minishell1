##
## EPITECH PROJECT, 2025
## minishell1
## File description:
## Makefile
##

CC	=	gcc

SRC	=	main.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

CFLAGS	=	-Wall -Wextra -Iinclude

all 	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(LCC) $(NAME) $(OBJ)
		ranlib $(NAME)

clean	:
		rm -f $(OBJ)

fclean 	:	clean
		rm -f $(NAME)

re	:	fclean all

coding-style	: clean
		~/coding-style-checker/coding-style.sh . .
		clear
		bat coding-style-reports.log
		rm -rf coding-style-reports.log
