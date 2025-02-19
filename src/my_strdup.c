/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** my_strdup
*/

#include <stdio.h>
#include "minishell.h"

char *my_strdup(char const *src)
{
    char *dest = malloc(sizeof(char) * my_strlen(src) + 1);

    my_strcpy(dest, src);
    return dest;
}
