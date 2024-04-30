/*
** EPITECH PROJECT, 2024
** src
** File description:
** mysh
*/
#include "mysh.h"

int print_env(list_t *chain)
{
    for (; chain; chain = chain->next) {
        my_putstr(chain->lines_env);
        my_putstr("\n");
    }
    return 0;
}
