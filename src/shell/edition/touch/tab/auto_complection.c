/*
** EPITECH PROJECT, 2022
** home_tab.c
** File description:
** Function : *
*/

#include "struct_all.h"
#include "my.h"

char *couper_chaine(char *chaine, int deplacement)
{
    if (deplacement < 0)
        return chaine;
    for (int n = 0; chaine[deplacement - 1] != '\0'; n++) {
        chaine[n] = chaine[deplacement];
        deplacement++;
    }
    chaine[deplacement] = '\0';
    return chaine;
}

char *ajouter_chaine(char *chaine, char *nouvelle_chaine, int position)
{
    int longueur = strlen(chaine);
    int longueur_nouvelle_chaine = strlen(nouvelle_chaine);
    if (position <= longueur) {
        memmove(chaine + position + longueur_nouvelle_chaine, chaine + position,
            longueur - position + 1);
        memcpy(chaine + position, nouvelle_chaine, longueur_nouvelle_chaine);
    }
    return chaine;
}

char *cut_chaine(char *first_tmp)
{
    int cut = (my_strlen(first_tmp));
    for (; cut >= 0; cut--) {
        if (first_tmp[cut] == '/' || first_tmp[cut] == ' ') {
            break;
        }
    }
    cut++;
    int n = 0;
    first_tmp[n] = first_tmp[cut];
    cut++;
    n++;
    for (; first_tmp[cut - 1] != '\0'; n++) {
        first_tmp[n] = first_tmp[cut];
        cut++;
    }
    return first_tmp;
}

int get_cut_chaine(i_s *info_shell)
{
    int pos = 0;
    char *first_tmp =
    my_strdup(info_shell->st_edit.list_cmd[info_shell->st_edit.pos_history]);
    first_tmp[(info_shell->st_edit.pos_in_cmd)] = '\0';
    first_tmp = cut_chaine(first_tmp);
    char *second_tmp = info_shell->st_edit.tmp_find_cmd;
    for (int pos = 0; first_tmp[pos] != '\0'; pos++) {
        if (strncmp_position(first_tmp, second_tmp, pos) != 0) {
            break;
        }
    }
    int result = my_strlen(first_tmp) - pos;
    return result;
}

void auto_complection(i_s *info_shell)
{
    if (info_shell->st_edit.size_tmp_display_tab == 0)
        return;
    get_complection(info_shell);
    if (my_strlen(info_shell->st_edit.tmp_find_cmd) >= my_strlen(
        info_shell->st_edit.tmp_display_tab[0])) {
        char *tmp = couper_chaine(info_shell->st_edit.tmp_find_cmd,
            get_cut_chaine(info_shell));
        if ((my_strlen(tmp) + my_strlen(info_shell->st_edit.list_cmd[
            info_shell->st_edit.pos_history]) > 1020))
            return;
        ajouter_chaine(info_shell->st_edit.list_cmd[
            info_shell->st_edit.pos_history], tmp,
                info_shell->st_edit.pos_in_cmd);
        info_shell->st_edit.pos_in_cmd += my_strlen(tmp);
    }
}
