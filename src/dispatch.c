/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** dispatch
*/

#include <stdlib.h>
#include "minishell.h"

static char **get_args(const char *line)
{
    char **args = parse_command(line);

    if (!args) {
        return NULL;
    }
    if (!args[0]) {
        free(args);
        return NULL;
    }
    return args;
}

static int attempt_builtin(char **args, char ***envp, int *return_code)
{
    int i = 0;

    if (check_builtin(args, envp, return_code)) {
        while (args[i]) {
            free(args[i]);
            i++;
        }
        free(args);
        return 1;
    }
    return 0;
}

void dispatch_command(const char *line, char ***envp, int *return_code)
{
    char **args = get_args(line);
    int i = 0;

    if (!args) {
        return;
    }
    if (attempt_builtin(args, envp, return_code)) {
        return;
    }
    *return_code = exec_command(args, envp);
    while (args[i]) {
        free(args[i]);
        i++;
    }
    free(args);
}
