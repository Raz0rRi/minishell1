/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** setenv_n_unsetenv
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "minishell.h"

int find_var_index(char **envp, const char *name)
{
    int i = 0;
    int len = 0;

    if (!envp || !name)
        return -1;
    len = my_strlen(name);
    while (envp[i]) {
        if (my_strncmp(envp[i], (char *)name, len)
        == 0 && envp[i][len] == '=') {
            return i;
        }
        i++;
    }
    return -1;
}

int realloc_env_for_new(char ***envp, char *new_line)
{
    char **old_env = *envp;
    int count = 0;
    char **new_env;
    int i;

    while (old_env[count]) {
        count++;
    }
    new_env = malloc(sizeof(char *) * (count + 2));
    if (!new_env) {
        return 84;
    }
    for (i = 0; i < count; i++) {
        new_env[i] = old_env[i];
    }
    new_env[count] = new_line;
    new_env[count + 1] = NULL;
    free(old_env);
    *envp = new_env;
    return 0;
}

static int remove_env_entry(char ***envp, int idx, int count)
{
    char **old_env = *envp;
    char **new_env = malloc(sizeof(char *) * count);
    int i = 0;
    int j = 0;

    if (!new_env)
        return 84;
    while (old_env[i]) {
        if (i == idx) {
            free(old_env[i]);
        } else {
            new_env[j] = old_env[i];
            j++;
        }
        i++;
    }
    new_env[j] = NULL;
    free(old_env);
    *envp = new_env;
    return 0;
}

int builtin_setenv(char ***envp, char **args)
{
    char *var_line;
    int ret;

    var_line = create_setenv_line(args);
    if (!var_line) {
        return 1;
    }
    ret = assign_setenv_var(envp, var_line, args[1]);
    return ret;
}

int builtin_unsetenv(char ***envp, char **args)
{
    int idx;
    int count = 0;

    if (!args[1]) {
        write(2, "unsetenv: Too few arguments.\n", 29);
        return 1;
    }
    idx = find_var_index(*envp, args[1]);
    if (idx < 0) {
        return 0;
    }
    while ((*envp)[count]) {
        count++;
    }
    if (remove_env_entry(envp, idx, count) == 84) {
        return 84;
    }
    return 0;
}
