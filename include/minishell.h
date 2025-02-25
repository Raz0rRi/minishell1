/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** minishell
*/

#ifndef MINISHELL_H_
    #define MINISHELL_H_
    #include <stdlib.h>
    #include <stdio.h>
    #include <errno.h>

char *read_line(void);
void shell_loop(void);
char **my_str_to_word_array(char *arr);
char **parse_command(const char *line);
char *my_strdup(char const *src);
int my_strcmp(const char *s1, const char *s2);
int my_strlen(const char *str);
int my_strncmp(char *s1, char *s2, int n);
char *my_strcpy(char *dest, char const *src);
char **copy_env(char **env);
void free_env(char **envp);
int builtin_cd(char **args);
int builtin_exit(char **args);
int my_getnbr(const char *str);
int builtin_cd(char **args);
int builtin_exit(char **args);
char *search_in_path(const char *cmd, char **env);
char *create_setenv_line(char **args);
int assign_setenv_var(char ***envp, char *var_line, const char *name);
int find_var_index(char **envp, const char *name);
int realloc_env_for_new(char ***envp, char *new_line);
char *create_var_line(const char *name, const char *value);
void fill_var_line(char *var_line,
    const char *name, const char *value);
int compute_var_line_size(const char *name, const char *value);
int builtin_env(char **envp);
int builtin_setenv(char ***envp, char **args);
int builtin_unsetenv(char ***envp, char **args);
void dispatch_command(const char *line, char ***envp, int *return_code);
int exec_command(char **args, char ***envp);
int check_builtin(char **args, char ***envp, int *return_code);

#endif /* MINISHELL_H_ */
