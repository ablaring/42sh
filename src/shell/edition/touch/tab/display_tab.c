/*
** EPITECH PROJECT, 2022
** display_tab.c
** File description:
** Function : *
*/

#include "struct_all.h"
#include "my.h"

int display_edition_tab_line(i_s *info_shell, int pos, int size_max,
    int max_display_in_shell)
{
    int n = 0;
    while (n < max_display_in_shell) {
        if (pos >= info_shell->st_edit.size_tmp_display_tab)
            break;
        if ((n + my_strlen(info_shell->st_edit.tmp_display_tab[pos]) + 5) >=
            info_shell->st_edit.size_term)
            break;
        color_tab_line(info_shell, pos);
        mini_printf("%s", info_shell->st_edit.tmp_display_tab[pos]);
        mini_printf(CDEF"");
        for (int i = 0; i < ((size_max + 4) -
            my_strlen(info_shell->st_edit.tmp_display_tab[pos])); i++)
            mini_printf(" ");
        n++;
        pos++;
    }
    mini_printf("\n");
    return pos;
}

void display_edition_tab_board(i_s *info_shell)
{
    int size_max = get_size_max_in_tab(info_shell);
    int max_display_in_shell = get_size_term() / (size_max + 4);
    int pos = 0;
    info_shell->st_edit.size_term = get_size_term();
    mini_printf("\n"CBLD);
    while (pos < info_shell->st_edit.size_tmp_display_tab) {
        pos = display_edition_tab_line(info_shell, pos, size_max,
            max_display_in_shell);
    }
    display_cmd_reset_cursor(info_shell);
}

void display_edition_tab(i_s *info_shell)
{
    display_edition_tab_board(info_shell);
    for (int n = 0; n < info_shell->st_edit.size_tmp_display_tab; n++) {
        free(info_shell->st_edit.tmp_display_tab[n]);
    }
    info_shell->st_edit.size_tmp_display_tab = 0;
}
