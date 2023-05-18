/*
** EPITECH PROJECT, 2022
** my_history.c
** File description:
** Function : my_history
*/

#include "struct_all.h"
#include "my.h"

int nombre_de_chiffres(int nombre)
{
    char buffer[20];
    int longueur;

    longueur = snprintf(buffer, 20, "%d", nombre);
    return longueur;
}

static void display_time(i_s *info_shell, int n)
{
    if (nombre_de_chiffres(info_shell->st_edit.hour[n]) == 1) {
        if (info_shell->st_pipe.nb_pipe == 0)
            printf("0%i", info_shell->st_edit.hour[n]);
        else
            dprintf(info_shell->st_pipe.pi[info_shell->st_pipe.pos][1],
                "0%i", info_shell->st_edit.hour[n]);
    } else {
        if (info_shell->st_pipe.nb_pipe == 0)
            printf("%i", info_shell->st_edit.hour[n]);
        else
            dprintf(info_shell->st_pipe.pi[info_shell->st_pipe.pos][1],
                "%i", info_shell->st_edit.hour[n]);
    }
    printf(":");
    error_history(info_shell, n);
}

void sub_display_history(i_s *info_shell, int n, int pos)
{
    if (strcmp(info_shell->st_edit.history[n],
        info_shell->st_edit.history[n + 1]) != 0) {
        for (int i = 6; i > nombre_de_chiffres(pos); i--)
            displ_hist(info_shell);
        if (info_shell->st_pipe.nb_pipe == 0)
            printf("%i  ", pos);
        else
            dprintf(info_shell->st_pipe.pi[info_shell->st_pipe.pos][1],
                "%i  ", pos);
        display_time(info_shell, n);
        if (info_shell->st_pipe.nb_pipe == 0)
            printf("   %s\n", info_shell->st_edit.history[n]);
        else
            dprintf(info_shell->st_pipe.pi[info_shell->st_pipe.pos][1],
                "   %s\n", info_shell->st_edit.history[n]);
    }
}

int display_history(i_s *info_shell)
{
    int pos = 1;
    strcpy(info_shell->st_edit.history[info_shell->st_edit.size_history], "\t");
    for (int n = (info_shell->st_edit.size_history - 1); n >= 0 ; n--) {
        sub_display_history(info_shell, n, pos);
        pos++;
    }
    return 0;
}

int my_history(i_s *info_shell, char *cmd)
{
    int nb_space = 0;
    for (int n = 0; cmd[n] != '\0'; n++) {
        if (cmd[n] == ' ')
            nb_space++;
    } if (nb_space > 1) {
        if (info_shell->st_pipe.nb_pipe == 0)
            dprintf(2, "history: Badly formed number.\n");
        else
            dprintf(info_shell->st_pipe.pi[info_shell->st_pipe.pos][1],
                "history: Badly formed number.\n");
        return 0;
    } if (my_strlen(cmd) > 10) {
        if (info_shell->st_pipe.nb_pipe == 0)
            dprintf(2, "history: Badly formed number.\n");
        else
            dprintf(info_shell->st_pipe.pi[info_shell->st_pipe.pos][1],
                "history: Badly formed number.\n");
        return 0;
    } error_frmat_history(info_shell, cmd);
    return (0);
}
