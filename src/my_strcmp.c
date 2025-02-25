/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** my_strcmp
*/

int my_strcmp(const char *s1, const char *s2)
{
    int i = 0;

    while (s1[i] && s1[i] == s2[i])
        i++;
    return (unsigned char)s1[i] - (unsigned char)s2[i];
}
