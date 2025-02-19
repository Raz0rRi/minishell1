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
char **copy_env(char **env);
void free_env(char **envp);
int builtin_cd(char **args);
int builtin_exit(char **args);
int my_getnbr(const char *str);
int builtin_cd(char **args);
int builtin_exit(char **args);
char *search_in_path(const char *cmd, char **env);

#endif /* MINISHELL_H_ */
