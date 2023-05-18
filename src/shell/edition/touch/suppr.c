/*
** EPITECH PROJECT, 2022
** suppr.c
** File description:
** Function : suppr
*/

#include "struct_all.h"
#include "my.h"

void suppr_in_struct(i_s *info_shell, int n)
{
    for (; n <= my_strlen(info_shell->st_edit.list_cmd[
            info_shell->st_edit.pos_history]); n++) {
        info_shell->st_edit.list_cmd[info_shell->st_edit.pos_history][n] =
        info_shell->st_edit.list_cmd[info_shell->st_edit.pos_history][n + 1];
    }
}

static void reset_suppr(i_s *info_shell)
{
    int save = info_shell->st_edit.pos_in_cmd / 1;
    int i = info_shell->st_edit.pos_in_cmd;
    for (; i < my_strlen(info_shell->st_edit.list_cmd[
        info_shell->st_edit.pos_history]); i++) {
        moove_right(info_shell);
        info_shell->st_edit.pos_in_cmd++;
    }
    info_shell->st_edit.size_term = get_size_term();
    info_shell->st_edit.pos_in_cmd = save;

    int stop = (my_strlen(info_shell->st_edit.list_cmd[
        info_shell->st_edit.pos_history]) + 13) /
            (info_shell->st_edit.size_term);
    write(1, "\33[2K\r", 5);
    for (int n = 0; n < stop; n++) {
        mini_printf("\033[1A");
        write(1, "\33[2K\r", 5);
    }
}

static void back_cursor_suppr(i_s *info_shell)
{
    info_shell->st_edit.size_term = get_size_term();
    if ((info_shell->st_edit.pos_in_cmd + 13) %
        ((info_shell->st_edit.size_term)) != 0)
        mini_printf("\b");
    else {
        for (int n = 1; n < info_shell->st_edit.size_term; n++)
            mini_printf("\x1B[1C");
        mini_printf("\033[1A");
    }
    info_shell->st_edit.pos_in_cmd--;
}

static void reset_cursor_suppr(i_s *info_shell)
{
    int save = info_shell->st_edit.pos_in_cmd / 1;
    int n = info_shell->st_edit.pos_in_cmd;
    info_shell->st_edit.pos_in_cmd = my_strlen(info_shell->st_edit.list_cmd[
        info_shell->st_edit.pos_history]);
    for (; n < (my_strlen(info_shell->st_edit.list_cmd[
        info_shell->st_edit.pos_history]));
            n++)
        back_cursor_suppr(info_shell);
    info_shell->st_edit.pos_in_cmd = save;
}

void suppr(i_s *info_shell)
{
    if (my_strlen(
        info_shell->st_edit.list_cmd[info_shell->st_edit.pos_history]) == 0)
        return;
    if (info_shell->st_edit.pos_in_cmd <= 0)
        return;

    reset_suppr(info_shell);
    suppr_in_struct(info_shell, info_shell->st_edit.pos_in_cmd - 1);
    info_shell->st_edit.pos_in_cmd--;

    print_deb();
    mini_printf("%s", info_shell->st_edit.list_cmd[
        info_shell->st_edit.pos_history]);
    if (((my_strlen(info_shell->st_edit.list_cmd[
        info_shell->st_edit.pos_history]) + 13) %
            (info_shell->st_edit.size_term)) == 0) {
        mini_printf(" ");
        mini_printf("\b");
    }
    reset_cursor_suppr(info_shell);
}
