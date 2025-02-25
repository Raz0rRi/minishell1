/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** check_builtin
*/

#include "minishell.h"

static int check_cd_exit(char **args, int *return_code)
{
    if (my_strcmp(args[0], "cd") == 0) {
        *return_code = builtin_cd(args);
        return 1;
    }
    if (my_strcmp(args[0], "exit") == 0) {
        *return_code = builtin_exit(args);
        return 1;
    }
    return 0;
}

static int check_env_setenv(char **args, char ***envp, int *return_code)
{
    if (my_strcmp(args[0], "env") == 0) {
        *return_code = builtin_env(*envp);
        return 1;
    }
    if (my_strcmp(args[0], "setenv") == 0) {
        *return_code = builtin_setenv(envp, args);
        return 1;
    }
    if (my_strcmp(args[0], "unsetenv") == 0) {
        *return_code = builtin_unsetenv(envp, args);
        return 1;
    }
    return 0;
}

int check_builtin(char **args, char ***envp, int *return_code)
{
    if (!args || !args[0]) {
        return 0;
    }
    if (check_cd_exit(args, return_code)) {
        return 1;
    }
    if (check_env_setenv(args, envp, return_code)) {
        return 1;
    }
    return 0;
}
