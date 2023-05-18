/*
** EPITECH PROJECT, 2022
** utils_display_tab.c
** File description:
** Function : *
*/

#include "struct_all.h"
#include "my.h"

int get_size_max_in_tab(i_s *info_shell)
{
    int size_max = 0;
    for (int n = 0; n < info_shell->st_edit.size_tmp_display_tab; n++) {
        if (my_strlen(info_shell->st_edit.tmp_display_tab[n]) > size_max)
            size_max = my_strlen(info_shell->st_edit.tmp_display_tab[n]);
    }
    return size_max;
}

void display_cmd_reset_cursor(i_s *info_shell)
{
    mini_printf(CDEF"");
    print_deb();
    mini_printf("%s", info_shell->st_edit.list_cmd[
        info_shell->st_edit.pos_history]);
    for (int n = 0; n < (my_strlen(info_shell->st_edit.list_cmd[
        info_shell->st_edit.pos_history]) - info_shell->st_edit.pos_in_cmd);
            n++) {
        back_cursor_delete(info_shell);
        info_shell->st_edit.pos_in_cmd++;
    }
}

void color_tab_line(i_s *info_shell, int pos)
{
    if (info_shell->st_edit.tmp_display_tab[pos][
        (my_strlen(info_shell->st_edit.tmp_display_tab[pos]) - 1)] == '/') {
        mini_printf(CCYN""CBLD);
        return;
    }
    if (info_shell->st_edit.is_cmd == 1) {
        mini_printf(CGRN""CBLD);
    } else {
        mini_printf(CMAG""CBLD);
    }
}
