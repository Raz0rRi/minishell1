/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** shell_loop
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "minishell.h"

void shell_loop(void)
{
    bool running = true;
    char *line;

    while (running) {
        write(1, "$> ", 3);
        line = read_line();
        if (!line) {
            write(1, "\n", 1);
            break;
        }
        if (line[0] == '\0') {
            free(line);
            continue;
        }
        free(line);
    }
}
