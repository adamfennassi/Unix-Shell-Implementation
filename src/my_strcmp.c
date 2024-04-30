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

int my_strncmp(const char *s1, const char *s2, int n)
{
    if (n == 0) {
        return 0;
    }
    while (n != 0) {
        if (*s1 != *s2) {
            return (*s1 > *s2) ? 1 : -1;
        }
        if (*s1 == '\0') {
            break;
        }
        s1++;
        s2++;
        n--;
    }
    return 0;
}
