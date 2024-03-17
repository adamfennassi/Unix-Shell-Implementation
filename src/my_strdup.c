/*
** EPITECH PROJECT, 2024
** src
** File description:
** mysh
*/

#include "mysh.h"


char *my_strdup(char *data)
{
    char *str = malloc(sizeof(char) * (my_strlen(data) + 1));

    str[my_strlen(data)] = '\0';
    for (int i = 0; data[i] != '\0'; i++)
        str[i] = data[i];
    return str;
}
