/*
** EPITECH PROJECT, 2022
** new_env.c
** File description:
** Function : new_env
*/

#include "struct_all.h"
#include "my.h"

int err_new_env(i_s *info_shell, char *arg)
{
    if (((arg[0] >= 'a' && arg[0] <= 'z') || (arg[0] >= 'A' && arg[0] <= 'Z'))
        || arg[0] == '_')
        return 0;
    if (info_shell->st_pipe.nb_pipe == 0)
        write_error("setenv: Variable name must begin with a letter.\n");
    else
        dprintf(info_shell->st_pipe.pi[info_shell->st_pipe.pos][1],
            "setenv: Variable name must begin with a letter.\n");
    info_shell->return_value = 1;
    return 1;
}

int new_env(i_s *info_shell, char *arg)
{
    if (err_new_env(info_shell, arg) == 1)
        return 0;
    if (info_shell->env[0] == NULL) {
        char **tmp_env = malloc(sizeof(char *) * (2));
        info_shell->size_env = 1;
        tmp_env[0] = arg;
        tmp_env[1] = NULL;
        info_shell->env = tmp_env;
        return 0;
    }
    int size_env = 0;
    for (; size_env < info_shell->size_env; size_env++);
    char **tmp_env = malloc(sizeof(char *) * (size_env + 2));
    for (int a = 0; a < size_env; a++)
        tmp_env[a] = info_shell->env[a];
    tmp_env[size_env] = arg;
    tmp_env[size_env + 1] = NULL;
    info_shell->env = tmp_env;
    info_shell->size_env++;
    return 0;
}
