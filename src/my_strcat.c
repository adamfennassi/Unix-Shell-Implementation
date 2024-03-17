/*
** EPITECH PROJECT, 2024
** src
** File description:
** mysh
*/

#include "mysh.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int j = 0;
    int length_dest = my_strlen(dest);
    int length_src = my_strlen(src);
    char *result = malloc(sizeof(char) * (length_dest + length_src + 1));

    result[length_dest + length_src] = '\0';
    while (i != length_dest) {
        result[i] = dest[i];
        i++;
    }
    while (j != length_src) {
        result[i] = src[j];
        j++;
        i++;
    }
    return result;
}
