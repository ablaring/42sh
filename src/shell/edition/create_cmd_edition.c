/*
** EPITECH PROJECT, 2022
** create_cmd_edition.c
** File description:
** Function : create_cmd_edition
*/

#include "struct_all.h"
#include "my.h"

int get_size_term(void)
{
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    return w.ws_col;
}

void sub_create_cmd_edition(i_s *info_shell, int ch)
{
    if (ch == '3') {
        ch = getchar();
        if (ch == '~')
            return delete(info_shell);
    } else {
        return flech_edition(info_shell, ch);
    }
}

void create_cmd_edition(i_s *info_shell, int ch)
{
    for (int n = 0; info_shell->st_edit.list_cmd[
        info_shell->st_edit.pos_history][n] != '\0'; n++)
        sub_get_cmd(info_shell->st_edit.list_cmd[
            info_shell->st_edit.pos_history], n);
    if (ch == '\t')
        return home_tab(info_shell);
    if (ch == 127)
        return suppr(info_shell);
    if (ch == '\x1b') {
        if ((ch = getchar()) == '[') {
            ch = getchar();
            return sub_create_cmd_edition(info_shell, ch);
        }
    }
    return write_caracter(info_shell, ch);
}
