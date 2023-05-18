/*
** EPITECH PROJECT, 2022
** write.c
** File description:
** Function : write
*/

#include "struct_all.h"
#include "my.h"

static void reset_write(i_s *info_shell)
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

static void add_caractter(i_s *info_shell, int ch)
{
    if (info_shell->st_edit.pos_in_cmd >= 1020)
        return;
    decale_cara(info_shell->st_edit.list_cmd[info_shell->st_edit.pos_history],
        info_shell->st_edit.pos_in_cmd);
    info_shell->st_edit.list_cmd[info_shell->st_edit.pos_history][
        info_shell->st_edit.pos_in_cmd] = ch;
    info_shell->st_edit.pos_in_cmd++;
}

static void reset_cursor_write(i_s *info_shell)
{
    int save = info_shell->st_edit.pos_in_cmd / 1;
    int n = info_shell->st_edit.pos_in_cmd;
    info_shell->st_edit.pos_in_cmd = my_strlen(info_shell->st_edit.list_cmd[
        info_shell->st_edit.pos_history]);
    for (; n < (my_strlen(info_shell->st_edit.list_cmd[
        info_shell->st_edit.pos_history]));
            n++)
        flech_left(info_shell);
    info_shell->st_edit.pos_in_cmd = save;
}

bool verif_cara_is_good_write(int ch)
{
    if (ch < 26)
        return false;
    return true;
}

void write_caracter(i_s *info_shell, int ch)
{
    if (verif_cara_is_good_write(ch) == false)
        return;
    if (my_strlen(info_shell->st_edit.list_cmd[
        info_shell->st_edit.pos_history]) > 1020)
        return;
    info_shell->st_edit.size_term = get_size_term();
    reset_write(info_shell);
    add_caractter(info_shell, ch);
    print_deb();
    mini_printf("%s", info_shell->st_edit.list_cmd[
        info_shell->st_edit.pos_history]);
    if (((info_shell->st_edit.pos_in_cmd + 13) %
    (info_shell->st_edit.size_term)) == 0) {
        mini_printf(" ");
        mini_printf("\b");
    }
    reset_cursor_write(info_shell);
}
