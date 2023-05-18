/*
** EPITECH PROJECT, 2022
** my_pwd.c
** File description:
** Function : my_pwd
*/

#include "struct_all.h"
#include "my.h"

void classic_echo(char *cmd, i_s *info_shell, char **tab)
{
    cmd = clean_echo(cmd, 5);
    cmd = trim_right(cmd);
    if (info_shell->st_pipe.nb_pipe == 0) {
        if (my_strcmp(tab[1], "-n") != 0)
            printf("%s\n", cmd);
    } else {
        if (my_strcmp(tab[1], "-n") != 0)
            dprintf(info_shell->st_pipe.pi[info_shell->st_pipe.pos][1],
                    "%s\n", cmd);
    }
}

bool quotes_right(char *cmd)
{
    char **tab = my_str_to_word_array(cmd, " ");
    int len = my_strlen(tab[1]);
    if ( len > 0 && tab[1][0] == '"' && tab[1][len - 1] != '"')
        return (true);
    return (false);
}

int my_pwd(i_s *info_shell, char *cmd)
{
    info_shell->st_cond.cmd_good = 1;
    if (nb_arg(cmd) != 1) {
        if (info_shell->st_pipe.nb_pipe == 0)
            dprintf(2, "pwd: ignoring non-option arguments\n");
        else
            dprintf(info_shell->st_pipe.pi[info_shell->st_pipe.pos][1],
                "pwd: ignoring non-option arguments\n");
        return 0;
    }
    if (nb_arg(cmd) == 1) {
        if (info_shell->st_pipe.nb_pipe == 0)
            dprintf(2, "%s\n", info_shell->dir);
        else
            dprintf(info_shell->st_pipe.pi[info_shell->st_pipe.pos][1],
                "%s\n", info_shell->dir);
        return 0;
    }
    info_shell->return_value = 0;
    return 0;
}
