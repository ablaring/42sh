/*
** EPITECH PROJECT, 2022
** utils_history.c
** File description:
** Function : *
*/

#include "struct_all.h"
#include "my.h"

void init_history(i_s *info_shell)
{
    info_shell->st_edit.history = malloc(sizeof(char *) * 254);
    info_shell->st_edit.size_history = 0;
    for (int n = 0; n < 253; n++)
        info_shell->st_edit.history[n] = malloc(sizeof(char) * 1024);
}

void add_cmd_history(i_s *info_shell, char *cmd)
{
    if (cmd[0] == '\0')
        return;
    if (my_strlen(cmd) > 1024)
        return;
    for (int i = info_shell->st_edit.size_history; i > 0; i--) {
        strcpy(info_shell->st_edit.history[i],
            info_shell->st_edit.history[i - 1]);
    }
    my_strcpy(info_shell->st_edit.history[0], cmd);
    if (info_shell->st_edit.size_history < 250)
        info_shell->st_edit.size_history++;
}

char *add_word(char *tmp, const char *str_add, int deb)
{
    int longueur_tmp = strlen(tmp);
    int longueur_str_add = strlen(str_add);
    if ((longueur_tmp + longueur_str_add) > 1020)
        return tmp;
    if (deb < 0 || deb > longueur_tmp)
        return tmp;

    int i = longueur_tmp;
    tmp[i + 1] = '\0';
    for (; i >= deb; --i)
        tmp[i + longueur_str_add] = tmp[i];
    for (int i = 0; i < longueur_str_add; ++i)
        tmp[deb + i] = str_add[i];
    return tmp;
}
