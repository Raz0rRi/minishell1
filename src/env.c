/*
** EPITECH PROJECT, 2025
** minishellzebi
** File description:
** env_setenv_unsetenv
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "minishell.h"

int builtin_env(char **envp)
{
    int i = 0;
    int len;

    if (!envp) {
        return 0;
    }
    while (envp[i]) {
        len = my_strlen(envp[i]);
        write(1, envp[i], len);
        write(1, "\n", 1);
        i++;
    }
    return 0;
}
