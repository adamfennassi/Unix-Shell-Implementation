/*
** EPITECH PROJECT, 2024
** src
** File description:
** mysh
*/

#include <stddef.h>

int my_strcmp(char *s1, char *s2)
{
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    if (*s1 < *s2) {
        return -1;
    } else if (*s1 > *s2) {
        return 1;
    } else {
        return 0;
    }
}
