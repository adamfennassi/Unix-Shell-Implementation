/*
** EPITECH PROJECT, 2024
** src
** File description:
** mysh
*/

#include "mysh.h"

char *remove_spaces(char *str)
{
    int i = 0;
    int x = 0;
    char *dest = malloc(sizeof(my_strlen(str)));

    while (str[i] != '\0') {
        if (str[i] == ' ' || str[i] == '\t') {
            i++;
        } else {
            dest[x] = str[i];
            x++;
            i++;
        }
    }
    dest[x] = '\0';
    return dest;
}

char **without_space(char **line_cmd)
{
    int i = 0;

    while (line_cmd[i]) {
        line_cmd[i] = remove_spaces(line_cmd[i]);
        i++;
    }
    return line_cmd;
}
