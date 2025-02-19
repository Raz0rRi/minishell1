/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** search_in_path
*/

#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include "minishell.h"

static char *get_path_var(char **env)
{
    int i = 0;

    while (env[i]) {
        if (my_strncmp(env[i], "PATH=", 5) == 0) {
            return env[i] + 5;
        }
        i++;
    }
    return NULL;
}

static void build_path(char *dest, const char *dir, const char *cmd)
{
    int i = 0;
    int j = 0;

    while (dir[i]) {
        dest[i] = dir[i];
        i++;
    }
    dest[i] = '/';
    i++;
    while (cmd[j]) {
        dest[i] = cmd[j];
        i++;
        j++;
    }
    dest[i] = '\0';
}

static int is_executable_file(const char *buffer)
{
    struct stat st;

    if (stat(buffer, &st) != 0) {
        return 0;
    }
    if (!S_ISREG(st.st_mode) && !S_ISLNK(st.st_mode)) {
        return 0;
    }
    if ((st.st_mode & 0111) == 0) {
        return 0;
    }
    return 1;
}

char *search_in_path(const char *cmd, char **env)
{
    char *path_var = get_path_var(env);
    char *save = my_strdup(path_var);
    char *token;
    char buffer[512];

    if (!path_var) {
        return NULL;
    }
    if (!save) {
        return NULL;
    }
    token = strtok(save, ":");
    while (token) {
        build_path(buffer, token, cmd);
        if (is_executable_file(buffer)) {
            free(save);
            return my_strdup(buffer);
        }
        token = strtok(NULL, ":");
    }
    free(save);
    return NULL;
}
