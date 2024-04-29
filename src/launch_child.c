/*
** EPITECH PROJECT, 2024
** src
** File description:
** mysh
*/

#include "mysh.h"

int access_is_possible(char *str)
{
    if (access(str, F_OK) == 0 && access(str, X_OK) == 0
        && access(str, R_OK) == 0)
        return 0;
    else
        return 84;
}

int choose_command(env_config_t *env_strct)
{
    if (env_strct->line_cmd[0][0] == '.' || env_strct->line_cmd[0][0] == '/') {
        if (access_is_possible(env_strct->line_cmd[0]) == 0) {
            env_strct->execute = env_strct->line_cmd[0];
            return 0;
        } else
            return 84;
    }
    for (int i = 0; env_strct->path[i]; i++) {
        env_strct->execute = my_strcat(env_strct->path[i], "/");
        env_strct->execute = my_strcat(env_strct->execute,
        env_strct->line_cmd[0]);
        if (access_is_possible(env_strct->execute) == 0)
            return 0;
    }
    return 0;
}

int error_checker(int status, env_config_t *env_strct)
{
    if (WTERMSIG(status) == 32) {
        write(2, env_strct->line_cmd[0], my_strlen(env_strct->line_cmd[0]));
        write(2, ": Command not found.\n", 21);
        return 1;
    }
    if (WTERMSIG(status) == 8) {
        write(2, "Floating execption", 18);
    } else
        write(2, strsignal(WTERMSIG(status)),
        my_strlen(strsignal(WTERMSIG(status))));
    if (WCOREDUMP(status))
        write(2, " (core dumped)", 14);
    write(2, "\n", 1);
    return 0;
}

int check_child_status(int status, env_config_t *env_strct)
{
    int res;

    if (WIFSIGNALED(status)) {
        res = error_checker(status, env_strct);
        if (res != 0)
            return res;
        if (WTERMSIG(status) == 8)
            return 136;
        return status;
    } else {
        return 0;
    }
}

int launch_child(env_config_t *env_strct)
{
    int res = choose_command(env_strct);
    pid_t child;
    int status;

    if (res != 0)
        return 84;
    child = fork();
    if (child == 0) {
        execve(env_strct->execute, env_strct->line_cmd, env_strct->env);
    } else if (child == -1) {
        my_putstr("error");
        return 84;
    } else {
        waitpid(child, &status, 0);
    }
    return check_child_status(status, env_strct);
}
