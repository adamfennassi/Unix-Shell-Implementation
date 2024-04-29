/*
** EPITECH PROJECT, 2024
** src
** File description:
** mysh
*/
#include "mysh.h"

int execute_shell(env_config_t *env_strct, list_t *list)
{
    int value = is_cmd(env_strct, list);

    if (value == -1)
        value = launch_child(env_strct);
    else if (value == 84)
        return 84;
    return value;
}

int launch_shell(list_t *list, env_config_t *env_strct)
{
    char *line_cmd = NULL;
    int verif;
    size_t size;

    while (1) {
        my_putstr("$> ");
        verif = getline(&line_cmd, &size, stdin);
        if (verif == -1) {
            my_putstr("exit\n");
            return 0;
        }
        line_cmd = remove_end_of_line(line_cmd);
        line_to_token(env_strct, line_cmd);
        env_strct->return_value = execute_shell(env_strct, list);
    }
}

char **init_env(char **env, env_config_t *env_strct)
{
    char *path = get_path(env);
    char *new_path = remove_prefix(path, "PATH=");
    int num_tokens = 0;
    char *token;
    int i = 0;
    char *copy_path;

    env_strct->env = get_env(env);
    copy_path = strdup(new_path);
    for (char *ptr = strtok(copy_path, ":");
    ptr != NULL; ptr = strtok(NULL, ":"))
        num_tokens++;
    env_strct->path = malloc(sizeof(char *) * (num_tokens + 1));
    for (token = strtok(new_path, ":");
    token != NULL; token = strtok(NULL, ":")) {
        env_strct->path[i] = my_strdup(token);
        i++;
    }
    env_strct->path[num_tokens] = NULL;
    return env_strct->path;
}

int main(int ac, char **av, char **env)
{
    env_config_t *env_struct = malloc(sizeof(env_config_t));
    list_t *shell_list = malloc(sizeof(list_t));

    if (ac != 1)
        return 84;
    if (init_env(env, env_struct) == NULL)
        return 84;
    shell_list = init_list(env);
    return launch_shell(shell_list, env_struct);
}
