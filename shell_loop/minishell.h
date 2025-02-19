/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** minishell
*/

#ifndef MINISHELL_H_
    #define MINISHELL_H_

char *read_line(void);
void shell_loop(void);
char **my_str_to_word_array(char *arr);
char **parse_command(const char *line);
char *my_strdup(char const *src);
char *my_strcpy(char *dest, char const *src);


#endif /* !MINISHELL_H_ */
