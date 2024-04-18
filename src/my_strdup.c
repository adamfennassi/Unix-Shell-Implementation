/*
** EPITECH PROJECT, 2024
** src
** File description:
** mysh
*/

#include "mysh.h"

char *my_strdup(char *data)
{
    int length = my_strlen(data);
    char *str = malloc(sizeof(char) * (length + 1));

    for (int i = 0; i < length; i++) {
        str[i] = data[i];
    }
    str[length] = '\0';
    return str;
}
