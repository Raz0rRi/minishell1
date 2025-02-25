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

extern char **environ;

void shell_loop(void)
{
    bool running = true;
    int return_code = 0;
    char **envp = copy_env(environ);
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
        dispatch_command(line, &envp, &return_code);
        free(line);
    }
    free_env(envp);
}
