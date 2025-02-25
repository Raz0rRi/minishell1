/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** exec_command
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include "minishell.h"

static int spawn_process(char *path, char **args, char **envp)
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid < 0) {
        perror("fork");
        free(path);
        return 84;
    }
    if (pid == 0) {
        if (execve(path, args, envp) == -1) {
            perror("execve");
            exit(84);
        }
    } else {
        waitpid(pid, &status, 0);
    }
    free(path);
    return WEXITSTATUS(status);
}

int exec_command(char **args, char ***envp)
{
    char *path = search_in_path(args[0], *envp);

    if (!path) {
        write(2, args[0], my_strlen(args[0]));
        write(2, ": Command not found.\n", 21);
        return 1;
    }
    return spawn_process(path, args, *envp);
}
