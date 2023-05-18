/*
** EPITECH PROJECT, 2023
** hitst
** File description:
** 2
*/

#include "struct_all.h"
#include "my.h"

int error_frmat_history(i_s *info_shell, char *cmd)
{
    if ((my_strlen(cmd) == 10) &&
        (cmd[7] == ' ' || cmd[8] == '-' || cmd[9] == 'c')) {
        info_shell->st_edit.size_history = 0;
        return 0;
    }
    if (my_strlen(cmd) == 7)
        return display_history(info_shell);
    if (my_strlen(cmd) > 10) {
        if (info_shell->st_pipe.nb_pipe == 0)
            dprintf(2, "history: Badly formed number.\n");
        else
            dprintf(info_shell->st_pipe.pi[info_shell->st_pipe.pos][1],
                "history: Badly formed number.\n");
        return info_shell->return_value = 1;
    }
    return (1);
}

void displ_hist(i_s *info_shell)
{
    if (info_shell->st_pipe.nb_pipe == 0)
        printf(" ");
    else
        dprintf(info_shell->st_pipe.pi
        [info_shell->st_pipe.pos][1], " ");
}

void error_history(i_s *info_shell, int n)
{
    if (nombre_de_chiffres(info_shell->st_edit.minute[n]) == 1) {
        if (info_shell->st_pipe.nb_pipe == 0)
            printf("0%i", info_shell->st_edit.minute[n]);
        else
            dprintf(info_shell->st_pipe.pi[info_shell->st_pipe.pos][1],
                "0%i", info_shell->st_edit.minute[n]);
    } else {
        if (info_shell->st_pipe.nb_pipe == 0)
            printf("%i", info_shell->st_edit.minute[n]);
        else
            dprintf(info_shell->st_pipe.pi[info_shell->st_pipe.pos][1],
                "%i", info_shell->st_edit.minute[n]);
    }
}
