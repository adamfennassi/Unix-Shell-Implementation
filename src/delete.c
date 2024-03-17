/*
** EPITECH PROJECT, 2024
** src
** File description:
** mysh
*/

#include "mysh.h"

int delete_head(list_t *element)
{
    element->next->prev = NULL;
    free(element);
    return 0;
}

int delete_tail(list_t *element)
{
    element->prev->next = NULL;
    free(element);
    return 0;
}

int delete_line_middle(list_t *element)
{
    element->next->prev = element->prev;
    element->prev->next = element->next;
    free(element);
    return 0;
}
