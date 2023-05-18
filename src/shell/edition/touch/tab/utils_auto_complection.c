/*
** EPITECH PROJECT, 2022
** utils_auto_complection.c
** File description:
** Function : *
*/

#include "struct_all.h"
#include "my.h"

int sub_get_complection(i_s *info_shell, int pos)
{
    char c = info_shell->st_edit.tmp_display_tab[0][pos];
    if (c == '\0')
        return 2;
    for (int n = 1; n < info_shell->st_edit.size_tmp_display_tab; n++) {
        if (info_shell->st_edit.tmp_display_tab[n][pos] != c)
            return 2;
    }
    info_shell->st_edit.tmp_find_cmd[pos] = c;
    return 0;
}

char *get_complection(i_s *info_shell)
{
    memset(info_shell->st_edit.tmp_find_cmd, 0, 2049);
    int pos = 0;
    while (true) {
        if (sub_get_complection(info_shell, pos) == 2)
            break;
        pos++;
    }
    return info_shell->st_edit.tmp_find_cmd;
}

int check_chaine_good(char *first_tmp, char *second_tmp, int pos)
{
    int n = 0;
    for (; first_tmp[pos] != '\0'; pos++) {
        if (n >= my_strlen(second_tmp))
            return 1;
        if (first_tmp[pos] != second_tmp[n])
            return 0;
        n++;
    }
    return 1;
}

int strncmp_position(char *chaine1, char *chaine2, int position)
{
    int longueur1 = strlen(chaine1);
    int longueur2 = strlen(chaine2);
    if (position >= 0 && position < longueur1 && position < longueur2) {
        return strncmp(chaine1 + position, chaine2 + position,
            longueur1 - position);
    } else if (position >= longueur1 && position >= longueur2) {
        return 1;
    }
    return 0;
}
