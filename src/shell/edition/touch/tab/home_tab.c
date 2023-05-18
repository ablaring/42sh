/*
** EPITECH PROJECT, 2022
** home_tab.c
** File description:
** Function : *
*/

#include "struct_all.h"
#include "my.h"

void home_tab(i_s *info_shell)
{
    get_display_tab(info_shell);
    if (info_shell->st_edit.size_tmp_display_tab == 0)
        return;
    if (info_shell->st_edit.no_file_find == 0)
        return;
    auto_complection(info_shell);
    display_edition_tab(info_shell);
}
