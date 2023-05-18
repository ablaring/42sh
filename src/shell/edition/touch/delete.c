/*
** EPITECH PROJECT, 2022
** delete.c
** File description:
** Function : delete
*/

#include "struct_all.h"
#include "my.h"
/*
** EPITECH PROJECT, 2022
** delete.c
** File description:
** Function : delete
*/

#include "struct_all.h"
#include "my.h"

void delete_in_struct(i_s *info_shell, int n)
{
    for (; n <= my_strlen(info_shell->st_edit.list_cmd[
            info_shell->st_edit.pos_history]); n++) {
        info_shell->st_edit.list_cmd[info_shell->st_edit.pos_history][n] =
        info_shell->st_edit.list_cmd[info_shell->st_edit.pos_history][n + 1];
    }
}

static void reset_delete(i_s *info_shell)
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

void back_cursor_delete(i_s *info_shell)
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

static void reset_cursor_delete(i_s *info_shell)
{
    int save = info_shell->st_edit.pos_in_cmd / 1;
    int n = info_shell->st_edit.pos_in_cmd;
    info_shell->st_edit.pos_in_cmd = my_strlen(info_shell->st_edit.list_cmd[
        info_shell->st_edit.pos_history]);
    for (; n < (my_strlen(info_shell->st_edit.list_cmd[
        info_shell->st_edit.pos_history]));
            n++)
        back_cursor_delete(info_shell);
    info_shell->st_edit.pos_in_cmd = save;
}

void delete(i_s *info_shell)
{
    if (info_shell->st_edit.pos_in_cmd < 0)
        return;

    reset_delete(info_shell);
    delete_in_struct(info_shell, info_shell->st_edit.pos_in_cmd);

    print_deb();
    mini_printf("%s", info_shell->st_edit.list_cmd[
        info_shell->st_edit.pos_history]);
    if (((my_strlen(info_shell->st_edit.list_cmd[
        info_shell->st_edit.pos_history]) + 13) %
            (info_shell->st_edit.size_term)) == 0) {
        mini_printf(" ");
        mini_printf("\b");
    }
    reset_cursor_delete(info_shell);
}
