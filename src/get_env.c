/*
** EPITECH PROJECT, 2024
** src
** File description:
** mysh
*/

#include "mysh.h"

char *remove_prefix(char *str, char *remove)
{
    char *res;
    int str_length = my_strlen(str);
    int delete_length = my_strlen(remove);
    int j = 0;

    res = malloc(sizeof(char) * (str_length - delete_length + 1));
    for (int i = delete_length; str[i]; i++){
        res[j] = str[i];
        j++;
    }
    res[j] = '\0';
    return res;
}

int get_len(char **env)
{
    int res = 0;

    for (int i = 0; env[i]; i++)
        res++;
    return res;
}

int nb_letters(char *env)
{
    int res = 0;

    for (int i = 0; env[i] != '\0'; i++) {
        res++;
    }
    return res + 1;
}

char **get_env(char **env)
{
    char **new_env;
    int len_env = get_len(env);
    int x = 0;

    new_env = malloc(sizeof(char *) * (len_env + 1));
    if (new_env == NULL)
        return NULL;
    new_env[len_env] = NULL;
    for (int i = 0; i < len_env; i++) {
        new_env[i] = malloc(sizeof(char) * (nb_letters(env[i])));
        for (; env[i][x] != '\0'; x++)
            new_env[i][x] = env[i][x];
        new_env[i][x] = '\0';
        x = 0;
    }
    return new_env;
}

char *get_path(char **env)
{
    char *path;

    for (int i = 0; env[i]; i++) {
        if (env[i][0] == 'P' && env[i][1] == 'A' &&
            env[i][2] == 'T' && env[i][3] == 'H') {
            path = env[i];
        }
    }
    path[my_strlen(path)] = '\0';
    return path;
}
