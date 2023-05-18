/*
** EPITECH PROJECT, 2022
** sub_boucle_shell.c
** File description:
** Function : shell
*/

#include "struct_all.h"
#include "my.h"

void sub_boucle_shell(void)
{
    print_deb();
    signal(SIGINT, sigint_signal_gesture);
    signal(SIGTSTP, sigtstp_handler);
}

void sub_sub_boucle_shell(i_s *info_shell, char **tab_cmd)
{
    int size = count_double_arr(tab_cmd);
    info_shell->is_single = 0;
    if (size >= 2)
        info_shell->is_single = 1;
}
