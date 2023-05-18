/*
** EPITECH PROJECT, 2022
** utils_get_tab.c
** File description:
** Function : *
*/

#include "struct_all.h"
#include "my.h"

int count_words(char* str)
{
    int number_word = 0;
    int pos_tmp = 0;
    while (*str != '\0') {
        if (!isspace(*str)) {
            number_word += !pos_tmp;
            pos_tmp = 1;
        } else {
            pos_tmp = 0;
        }
        str++;
    }
    return number_word;
}

void sub_tab_cmd(i_s *info_shell)
{
    my_strcpy(info_shell->st_edit.tmp_tab, info_shell->st_edit.list_cmd[
        info_shell->st_edit.pos_history]);
    info_shell->st_edit.tmp_tab[(info_shell->st_edit.pos_in_cmd)] = '\0';
    int nb_word = count_words(info_shell->st_edit.tmp_tab);

    char **tab_tab = my_str_to_word_array(info_shell->st_edit.tmp_tab, " ");
    memset(info_shell->st_edit.tmp_tab, 0, 2048);
    my_strcpy(info_shell->st_edit.tmp_tab, tab_tab[nb_word - 1]);
}

void get_tab_cmd(i_s *info_shell)
{
    info_shell->st_edit.tmp_tab =
        malloc(sizeof(char) * 2054);
    memset(info_shell->st_edit.tmp_tab, 0, 2054);
    if (my_strlen(
        info_shell->st_edit.list_cmd[info_shell->st_edit.pos_history]) > 2048)
        return;
    if (info_shell->st_edit.pos_in_cmd == 0) {
        info_shell->st_edit.tmp_tab = "./";
        return;
    }
    if (info_shell->st_edit.list_cmd[info_shell->st_edit.pos_history][
        info_shell->st_edit.pos_in_cmd - 1] == ' ')
        return;
    sub_tab_cmd(info_shell);
}
