/*
** EPITECH PROJECT, 2022
** shell.c
** File description:
** Function : shell
*/

#include "struct_all.h"
#include "my.h"

void start_cmd_end(i_s *info_shell, char *cmd, char *one_arg)
{
    if (my_other(info_shell, cmd, one_arg) == -1) {
        double_write(one_arg, ": Command not found.\n");
        info_shell->return_value = 1;
        info_shell->st_cond.cmd_good = 0;
    }
}

int start_cmd_debut(i_s *info_shell, char **cmd)
{
    if (info_shell->stop == 1 || *cmd[0] == '\0' ||
    info_shell->st_redi.err_redir == 84)
        return 0;
    if (check_special_var(info_shell, *cmd) == 1)
        return 0;
    if (check_if_varenv(*cmd))
        if (if_arg_variable_env(info_shell, *cmd, &*cmd) == 1)
            return 1;
    return 2;
}
