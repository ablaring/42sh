/*
** EPITECH PROJECT, 2022
** history.c
** File description:
** Function : *
*/

#include "struct_all.h"
#include "my.h"

static char *delete_word(char *chaine, int deb, int end)
{
    int longueur = strlen(chaine);
    int i, j;
    if (deb < 0 || end >= longueur || deb > end) {
        return chaine;
    }

    for (i = deb, j = end + 1; j <= longueur; ++i, ++j) {
        chaine[i] = chaine[j];
    }
    chaine[i] = '\0';

    return chaine;
}

void sub_sub_change_cmd_history(i_s *info_shell, char *nbr)
{
    if (my_strlen(nbr) > 9)
        nbr = strdup("276447232");
    if (info_shell->st_pipe.nb_pipe == 0) {
        dprintf(2, "%s: Event not found.\n", nbr);
    } else {
        dprintf(info_shell->st_pipe.pi[info_shell->st_pipe.pos][1],
            "%s: Event not found.\n", nbr);
    }
    info_shell->return_value = 1;
    info_shell->st_edit.not_start_cmd = 1;
}

char *sub_change_cmd_history(i_s *info_shell, char *tmp, int n)
{
    char *nbr = malloc(sizeof(char) * (my_strlen(tmp) + 2));
    memset(nbr, 0, (my_strlen(tmp) + 2));
    int pos = init_pos_history(info_shell);
    int deb = n;
    for (n++; tmp[n] != '\0'; n++) {
        if (tmp[n] < '0' || tmp[n] > '9')
            break;
        nbr[pos++] = tmp[n];
    }
    if (strlen(nbr) > 0) {
        tmp = delete_word(tmp, deb, (n - 1));
        int position = info_shell->st_edit.size_history - atoi(nbr);
        if (position > info_shell->st_edit.size_history ||
            info_shell->st_edit.size_history <= 0)
            sub_sub_change_cmd_history(info_shell, nbr);
        else
            tmp = add_word(tmp, info_shell->st_edit.history[position], deb);
    }
    free(nbr);
    return tmp;
}

char *change_cmd_history(i_s *info_shell, char *tmp)
{
    for (int n = 0; my_strlen(tmp) > n; n++) {
        if (tmp[n] == '!' && (tmp[n + 1] > '0' && tmp[n + 1] < '9')) {
            tmp = sub_change_cmd_history(info_shell, tmp, n);
        }
        if (n >= my_strlen(tmp))
            return tmp;
    }
    return tmp;
}
