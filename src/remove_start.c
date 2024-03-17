/*
** EPITECH PROJECT, 2024
** src
** File description:
** mysh
*/

#include "mysh.h"

char *remove_end(char *str)
{
    int length = my_strlen(str) - 1;
    char *new_str = malloc(sizeof(char) * (length + 1));

    if (new_str == NULL || str == NULL)
        return NULL;
    new_str[length] = '\0';
    for (int i = 0; i < length; i++) {
        new_str[i] = str[i];
    }
    return new_str;
}

char *remove_start(char *str, char *delete)
{
    char *final_str = NULL;
    int str_length = my_strlen(str);
    int delete_length = my_strlen(delete);
    int j = 0;

    if (delete_length >= str_length)
        return NULL;
    final_str = malloc(sizeof(char) * (str_length - delete_length + 1));
    if (final_str == NULL)
        return NULL;
    for (int i = delete_length; str[i]; i++){
        final_str[j] = str[i];
        j++;
    }
    final_str[j] = '\0';
    return final_str;
}
