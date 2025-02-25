/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** my_strncmp
*/

static int cond_1(char *s1, char *s2, int v)
{
    if (s1[v] > s2[v]) {
        return 1;
    } else {
        return -1;
    }
}

static int cond_2(char *s1, char *s2, int v)
{
    if (s1[v] == '\0' && s2[v] == '\0') {
        return 0;
    } else if (s1[v] == '\0') {
        return -1;
    } else {
        return 1;
    }
}

int my_strncmp(char *s1, char *s2, int n)
{
    int v = 0;

    while (v < n && s1[v] != '\0' && s2[v] != '\0') {
        if (s1[v] != s2[v]) {
            return cond_1(s1, s2, v);
        }
        v++;
    }
    if (v < n) {
        return cond_2(s1, s2, v);
    }
    return 0;
}
