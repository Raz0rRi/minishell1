/*
** EPITECH PROJECT, 2025
** minishellzebi
** File description:
** builtin_env_help
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "minishell.h"

char *create_setenv_line(char **args)
{
    char *var_line;

    if (!args[1]) {
        write(2, "setenv: Too few arguments.\n", 27);
        return NULL;
    }
    var_line = create_var_line(args[1], args[2] ? args[2] : "");
    return var_line;
}

int assign_setenv_var(char ***envp, char *var_line, const char *name)
{
    int idx = find_var_index(*envp, name);

    if (idx >= 0) {
        free((*envp)[idx]);
        (*envp)[idx] = var_line;
    } else {
        if (realloc_env_for_new(envp, var_line) == 84) {
            free(var_line);
            return 84;
        }
    }
    return 0;
}
