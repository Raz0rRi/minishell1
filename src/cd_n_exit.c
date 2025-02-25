/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** cd_n_exit
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "minishell.h"

int builtin_cd(char **args)
{
    int ret;

    if (!args[1]) {
        write(2, "cd: Too few arguments.\n", 23);
        return 1;
    }
    ret = chdir(args[1]);
    if (ret != 0) {
        perror("cd");
        return 1;
    }
    return 0;
}

int builtin_exit(char **args)
{
    int code = 0;

    if (args[1]) {
        code = my_getnbr(args[1]);
    }
    exit(code);
    return 0;
}
