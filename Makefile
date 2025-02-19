##
## EPITECH PROJECT, 2025
## minishell1
## File description:
## Makefile
##

CC	=	gcc

SRC	=	main.c			\
		shell_loop.c 	\
		read_line.c		\
		my_strcpy.c		\
		my_strdup.c		\
		my_str_to_word_array.c 	\
		parse_command.c \
		cd_n_exit.c 	\

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
