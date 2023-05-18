/*
** EPITECH PROJECT, 2022
** and_or.c
** File description:
** Function : and_or
*/

#include "struct_all.h"
#include "my.h"

// if == 1 continue or 0 not continue
int condition_and_or(i_s *info_shell, char **tab_or_and, int n)
{
    if (n >= (info_shell->st_cond.size_and_or - 1))
        return 1;
    if (tab_or_and[n][0] == '&') {
        if (info_shell->return_value == 0)
            return 1;
        else
            return 0;
    }
    if (tab_or_and[n][0] == '|') {
        if (info_shell->return_value == 0)
            return 0;
        else
            return 1;
    }
    return 1;
}

void reset_and_or(i_s *info_shell)
{
    info_shell->st_pipe.pos = 0;
    info_shell->st_pipe.nb_pipe = 0;
    info_shell->st_pipe.pos_max = 0;
    info_shell->st_redi.err_redir = 0;
}

int sub_and_or(i_s *info_shell, char **tab_cmd, int n, int tmp)
{
    if (is_piped(tab_cmd[n]) == 1) {
        main_pipe(info_shell, my_cleaner(tab_cmd[n]));
    } else {
        reset_and_or(info_shell);
        tmp = start_cmd(info_shell, my_cleaner(tab_cmd[n]));
    }
    return tmp;
}

int and_or(i_s *info_shell, char *cmd)
{
    if (verif_error_and_or(cmd, info_shell) == 1)
        return 0;
    char **tab_or_and = get_or_and(info_shell, cmd);
    char **tab_cmd = get_cmd_or_and(info_shell, cmd);
    int tmp = 0;
    info_shell->st_cond.cmd_good = 1;
    for (int n = 0; n < info_shell->st_cond.size_cmd_and_or; n++) {
        if (condition_and_or(info_shell, tab_or_and, n) == 1)
            tmp = sub_and_or(info_shell, tab_cmd, n, tmp);
        if (tmp != 0){
            info_shell->return_value = tmp;
            return tmp;
        }
    }
    return 0;
}
