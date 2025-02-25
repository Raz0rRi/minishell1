/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** create_var_line
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "minishell.h"

int compute_var_line_size(const char *name, const char *value)
{
    int len_name = my_strlen(name);
    int len_val = 0;

    if (value) {
        len_val = my_strlen(value);
    }
    return (len_name + 1 + len_val + 1);
}

void fill_var_line(char *var_line,
    const char *name, const char *value)
{
    int i = 0;
    int j = 0;

    while (name[i]) {
        var_line[i] = name[i];
        i++;
    }
    var_line[i] = '=';
    i++;
    while (value && value[j]) {
        var_line[i] = value[j];
        i++;
        j++;
    }
    var_line[i] = '\0';
}

char *create_var_line(const char *name, const char *value)
{
    int size = compute_var_line_size(name, value);
    char *var_line = malloc(sizeof(char) * size);

    if (!var_line) {
        return NULL;
    }
    fill_var_line(var_line, name, value);
    return var_line;
}
