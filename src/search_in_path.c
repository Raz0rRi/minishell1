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

static char *search_in_path_loop(char *save, const char *cmd)
{
    char buffer[512];
    char *token = strtok(save, ":");

    while (token) {
        build_path(buffer, token, cmd);
        if (is_executable_file(buffer)) {
            return my_strdup(buffer);
        }
        token = strtok(NULL, ":");
    }
    return NULL;
}

char *search_in_path(const char *cmd, char **env)
{
    char *path_var = get_path_var(env);
    char *save;
    char *result;

    if (!path_var) {
        return NULL;
    }
    save = my_strdup(path_var);
    if (!save) {
        return NULL;
    }
    result = search_in_path_loop(save, cmd);
    free(save);
    return result;
}
