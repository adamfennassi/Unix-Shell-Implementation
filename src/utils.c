/*
** EPITECH PROJECT, 2024
** src
** File description:
** mysh
*/
#include "mysh.h"

char *remove_end_of_line(char *str)
{
    size_t len = strlen(str);
    int i = len;

    while (i > 0 && (str[i - 1] == ' ' || str[i - 1] == '\t' ||
    str[i - 1] == '\n')) {
        i--;
    }
    if (i > 0) {
        str[i] = '\0';
    }
    return str;
}

void line_to_token(env_config_t *env, char *line)
{
    char *token;
    int MAX_TOKENS = 100000;
    int i = 0;

    env->line_cmd = malloc(sizeof(char *) * MAX_TOKENS);
    token = strtok(line, " \t");
    while (token != NULL) {
        if (my_strlen(token) > 0) {
            env->line_cmd[i] = my_strdup(token);
            i++;
        }
        token = strtok(NULL, " \t");
    }
}

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

int delete_middle(list_t *element)
{
    element->next->prev = element->prev;
    element->prev->next = element->next;
    free(element);
    return 0;
}
