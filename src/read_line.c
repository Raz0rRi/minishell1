/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** read_line
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "minishell.h"

char *read_line(void)
{
    char *line = NULL;
    size_t n = 0;
    ssize_t len = getline(&line, &n, stdin);

    if (len < 0) {
        free(line);
        return NULL;
    }
    if (len > 0 && line[len - 1] == '\n') {
        line[len - 1] = '\0';
    }
    return line;
}
