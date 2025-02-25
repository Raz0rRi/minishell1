##
## EPITECH PROJECT, 2025
## minishell1
## File description:
## Makefile
##

CC	=	gcc

SRC	=	src/main.c			\
		src/shell_loop.c 	\
		src/read_line.c		\
		src/my_strcpy.c		\
		src/my_strdup.c		\
		src/my_strcmp.c	\
		src/my_str_to_word_array.c 	\
		src/parse_command.c \
		src/cd_n_exit.c 	\
		src/builtin_env_help.c \
		src/create_var_line.c \
		src/env_manager.c \
		src/env.c \
		src/search_in_path.c \
		src/check_builtin.c \
		src/exec_command.c \
		src/setenv_n_unsetenv.c \
		src/dispatch.c \
		src/my_strlen.c \
		src/my_strncmp.c \
		src/my_getnbr.c \

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

CFLAGS	=	-Wall -Wextra -Iinclude

all 	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

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
