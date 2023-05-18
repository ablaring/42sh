/*
** EPITECH PROJECT, 2022
** get_display_tab.c
** File description:
** Function : *
*/

#include "struct_all.h"
#include "my.h"

void change_tmp_tab_edition(i_s *info_shell)
{
    if (info_shell->st_edit.tmp_tab[0] == '\0') {
        my_strcpy(info_shell->st_edit.tmp_tab, "./");
    }
}

char **get_display_tab(i_s *info_shell)
{
    get_tab_cmd(info_shell);
    if (info_shell->st_edit.tmp_tab[0] != '\0')
        get_tab_is_cmd(info_shell);
    if (info_shell->st_edit.size_tmp_display_tab != 0) {
        info_shell->st_edit.no_file_find = 1;
        info_shell->st_edit.is_cmd = 1;
        return info_shell->st_edit.tmp_display_tab;
    }
    change_tmp_tab_edition(info_shell);
    info_shell->st_edit.is_cmd = 0;
    if (get_tab_file_in_path(info_shell, NULL, 0) != 2) {
        info_shell->st_edit.no_file_find = 1;
        return info_shell->st_edit.tmp_display_tab;
    }
    if (find_directory(info_shell, info_shell->st_edit.tmp_tab) != 2) {
        info_shell->st_edit.no_file_find = 1;
        return info_shell->st_edit.tmp_display_tab;
    }
    info_shell->st_edit.no_file_find = 0;
    return info_shell->st_edit.tmp_display_tab;
}
