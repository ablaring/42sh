/*
** EPITECH PROJECT, 2022
** shell.c
** File description:
** Function : shell
*/

#include "struct_all.h"
#include "my.h"


void star_cmd_suite(i_s *info_shell, int tmp)
{
    if (info_shell->nb_buildin == 3 && tmp == 0)
        stock_variable(info_shell);
}

int check_special_var(i_s *info_shell, char *cmd)
{
    if (my_strcmp(cmd, "$HOME") == 0) {
        chdir(info_shell->home);
        return (1);
    }
    return (0);
}
