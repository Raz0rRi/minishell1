/*
** EPITECH PROJECT, 2025
** mysh
** File description:
** environment manager (part 5)
*/

#include <stdlib.h>
#include <string.h>
#include "minishell.h"

char **copy_env(char **env)
{
    int count = 0;
    char **env_copy;
    int i;

    while (env[count]) {
        count++;
    }
    env_copy = malloc(sizeof(char *) * (count + 1));
    if (!env_copy)
        return NULL;
    for (i = 0; i < count; i++) {
        env_copy[i] = my_strdup(env[i]);
    }
    env_copy[count] = NULL;
    return env_copy;
}

void free_env(char **envp)
{
    int i = 0;

    if (!envp)
        return;
    while (envp[i]) {
        free(envp[i]);
        i++;
    }
    free(envp);
}
