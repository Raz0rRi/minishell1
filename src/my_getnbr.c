/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** my_getnbr
*/

#include <limits.h>

int my_getnbr(const char *str)
{
    int result = 0;
    int sign = 1;

    while (*str == '-' || *str == '+') {
        if (*str == '-') {
            sign *= -1;
        }
        str++;
    }
    while (*str != '\0' && *str >= '0' && *str <= '9') {
        result = result * 10 + (*str - '0');
        str++;
    }
    result *= sign;
    return result;
}
