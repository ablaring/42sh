/*
** EPITECH PROJECT, 2022
** my_setenv.c
** File description:
** Function : setenv
*/

#include "struct_all.h"
#include "my.h"

int in_env(char *env, char *cmd)
{
    int size_env = my_strlen(env);
    int size_cmd = my_strlen(cmd);
    if (size_env < (size_cmd + 1))
        return 0;
    if (my_strncmp(env, cmd, size_cmd) == 0 && env[size_cmd] == '=') {
        return 1;
    }
    return 0;
}

int cherch_arg_env(i_s *info_shell, char *cmd)
{
    for (int a = 0; a < info_shell->size_env; a++) {
        if (in_env(info_shell->env[a], cmd) == 1)
            return a;
    }
    return -1;
}

int write_error_setenv(i_s *info_shell, int pos,
    __attribute__((unused))char *cmd, __attribute__((unused))char **tmp)
{
    char *msg = "setenv: Variable name must contain alphanumeric characters.\n";
    if (pos == 1) {
        if (info_shell->st_pipe.nb_pipe == 0)
            write_error("setenv: Too many arguments.\n");
        else
            dprintf(info_shell->st_pipe.pi[info_shell->st_pipe.pos][1],
                "setenv: Too many arguments.\n");
        return info_shell->return_value = 1;
    } else {
        if (info_shell->st_pipe.nb_pipe == 0)
            write_error(msg);
        else
            dprintf(info_shell->st_pipe.pi[info_shell->st_pipe.pos][1], msg);
        return info_shell->return_value = 1;
    }
}

int my_setenv_suite_suite(char **tmp, char *cmd, i_s *info_shell)
{
    for (int n = 0; tmp[1][n] != '\0'; n++) {
        if (tmp[1][n] == '=') {
            write_error_setenv(info_shell, 2, cmd, tmp);
            return 1;
        }
    }
    return 0;
}

int my_setenv(i_s *info_shell, char *cmd)
{
    if (cmd[(strlen(cmd) - 1)] == ' ')
        cmd[(strlen(cmd) - 1)] = '\0';
    info_shell->st_cond.cmd_good = 1;
    if (nb_arg(cmd) == 1)
        return my_env(info_shell, "env");
    char **tmp = my_str_to_word_array(cmd, " ");
    if (nb_arg(cmd) == 4) {
        write_error_setenv(info_shell, 1, cmd, tmp);
        return info_shell->return_value = 1;
    }
    if (tmp[1] == NULL)
        return 0;
    if (tmp[1][0] < 'A' || (tmp[1][0] > 'Z' && tmp[1][0] < 'a') ||
        tmp[1][0] > 'z') {
        printf("%s: Variable name must begin with a letter.\n", tmp[0]);
        return info_shell->return_value = 1;
    }
    if (my_setenv_suite_suite(tmp, cmd, info_shell) == 1)
        return info_shell->return_value = 1;
    return (my_setenv_suite(info_shell, cmd));
}
