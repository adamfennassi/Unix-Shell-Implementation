/*
** EPITECH PROJECT, 2024
** src
** File description:
** mysh
*/

#include "mysh.h"

int number_chara(char *buffer, int i, char c)
{
    int y = 0;
    int counter = 0;

    while (i != 0) {
        while (buffer[y] == ' ' || buffer[y] == '\n' || buffer[y] == '\t')
            y++;
        while (buffer[y] != c && buffer[y] != '\n' && buffer[y])
            y++;
        y++;
        i--;
    }
    while (buffer[y] == ' ' || buffer[y] == '\n' || buffer[y] == '\t')
        y++;
    while (buffer[y] != c && buffer[y] && buffer[y] != ' '
    && buffer[y] != '\n' && buffer[y] != '\t') {
        counter++;
        y++;
    }
    return counter;
}

int number_lines(char *buffer, char c)
{
    int i = 0;
    int counter = 0;

    while ((buffer[i] == ' ' || buffer[i] == '\n' ||
    buffer[i] == '\t') && buffer[i] != '\0')
        i++;
    while (buffer[i] != '\0') {
        if (buffer[i] == c)
            counter++;
        while ((buffer[i] == ' ' || buffer[i] == '\n' ||
        buffer[i] == '\t') && buffer[i] != '\0')
            i++;
        i++;
    }
    if (buffer[i - 2] == ' ' || buffer[i - 2] == '\t' || buffer[i - 2] == '\n'
    || buffer[i - 1] == ' ' || buffer[i - 1] == '\t' || buffer[i - 1] == '\n')
        counter--;
    return counter + 1;
}

char *fill_array(char c, char *buffer, char *array, int *k)
{
    int j = 0;

    while (buffer[*k] == ' ' || buffer[*k] == '\n' ||
    buffer[*k] == '\t' || buffer[*k] == '\0' || buffer[*k] == c)
        (*k)++;
    for (; buffer[*k] != c && buffer[*k] != '\0' && buffer[*k] != '\n'
    && buffer[*k] != '\t' && buffer[*k] != ' '; (*k)++) {
        array[j] = buffer[*k];
        j++;
    }
    return array;
}

char **my_str_to_word_array(char *buffer, char c)
{
    int lines = number_lines(buffer, c);
    char **array = malloc(sizeof(char *) * (lines + 1));
    int i = 0;
    int k = 0;

    array[lines] = NULL;
    for (; i < lines; i++){
        array[i] = malloc(sizeof(char) * (number_chara(buffer, i, c) + 1));
        array[i][number_chara(buffer, i, c)] = '\0';
        array[i] = fill_array(c, buffer, array[i], &k);
    }
    return array;
}
