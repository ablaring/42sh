/*
** EPITECH PROJECT, 2022
** flech_up.c
** File description:
** Function : flech_up
*/

#include "struct_all.h"
#include "my.h"

static void reset_flech_up(i_s *info_shell)
{
    int save = info_shell->st_edit.pos_in_cmd / 1;
    int i = info_shell->st_edit.pos_in_cmd;
    for (; i < my_strlen(info_shell->st_edit.list_cmd[
        info_shell->st_edit.pos_history]); i++) {
        moove_right(info_shell);
        info_shell->st_edit.pos_in_cmd++;
    }

    int stop = (my_strlen(info_shell->st_edit.list_cmd[
        info_shell->st_edit.pos_history]) + 13) /
        info_shell->st_edit.size_term;
    write(1, "\33[2K\r", 5);
    for (int n = 0; n < stop; n++) {
        mini_printf("\033[1A");
        write(1, "\33[2K\r", 5);
    }
    info_shell->st_edit.pos_in_cmd = save;
}

void flech_up(i_s *info_shell)
{
    if (info_shell->st_edit.pos_history >= info_shell->st_edit.size_list_cmd)
        return;
    reset_flech_up(info_shell);

    info_shell->st_edit.pos_history++;
    info_shell->st_edit.pos_in_cmd = my_strlen(
        info_shell->st_edit.list_cmd[info_shell->st_edit.pos_history]);

    print_deb();
    mini_printf("%s", info_shell->st_edit.list_cmd[
        info_shell->st_edit.pos_history]);
    if (((info_shell->st_edit.pos_in_cmd + 13) %
        (info_shell->st_edit.size_term)) == 0) {
        mini_printf(" ");
        mini_printf("\b");
    }
}
