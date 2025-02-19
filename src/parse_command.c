/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** parse_command
*/

#include <stdlib.h>
#include "minishell.h"

char **parse_command(const char *line)
{
    char *dup = NULL;
    char **args = NULL;

    if (!line || line[0] == '\0')
        return NULL;
    dup = my_strdup(line);
    if (!dup)
        return NULL;
    args = my_str_to_word_array(dup);
    free(dup);
    return args;
}
