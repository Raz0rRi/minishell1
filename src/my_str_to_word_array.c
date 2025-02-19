/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>

static int count_words(char *str, char cut)
{
    int words = 0;
    int in_word = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != cut && !in_word) {
            words++;
            in_word = 1;
        }
        if (str[i] == cut) {
            in_word = 0;
        }
    }
    return words;
}

static void copy_word_to_array(char **res, char *arr,
    int *indices, int word_index)
{
    int word_len = indices[1] - indices[0];

    res[word_index] = malloc(sizeof(char) * (word_len + 1));
    for (int i = 0; i < word_len; i++) {
        res[word_index][i] = arr[indices[0] + i];
    }
    res[word_index][word_len] = '\0';
}

char **my_str_to_word_array(char *arr)
{
    int nb_words = count_words(arr, ' ');
    char **res = malloc(sizeof(char *) * (nb_words + 1));
    int word_start = -1;
    int word_index = 0;
    int indices[2];

    for (int i = 0; arr[i] != '\0'; i++) {
        if (arr[i] != ' ' && word_start == -1) {
            word_start = i;
        }
        if ((arr[i] == ' ' || arr[i + 1] == '\0') && word_start != -1) {
            indices[0] = word_start;
            indices[1] = (arr[i] == ' ') ? i : i + 1;
            copy_word_to_array(res, arr, indices, word_index++);
            word_start = -1;
        }
    }
    res[word_index] = NULL;
    return res;
}
