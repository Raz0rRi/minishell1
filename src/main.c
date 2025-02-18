/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** main
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "minishell.h"

int main(int ac, char **av, char **env)
{
    (void)av;
    (void)env;
    if (ac != 1) {
        write(2, "Usage: ./mysh\n", 14);
        return 84;
    }
    shell_loop();
    return 0;
}
