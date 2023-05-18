/*
** EPITECH PROJECT, 2022
** get_cmd.c
** File description:
** Function : *
*/

#include "struct_all.h"
#include "my.h"

void save_time(i_s *info_shell)
{
    for (int n = (info_shell->st_edit.size_history - 1); n >= 0; n--) {
        info_shell->st_edit.hour[n + 1] = info_shell->st_edit.hour[n];
        info_shell->st_edit.minute[n + 1] = info_shell->st_edit.minute[n];
    }
    time_t temps_actuel = time(NULL);
    struct tm *heure_locale = localtime(&temps_actuel);
    info_shell->st_edit.hour[0] = heure_locale->tm_hour;
    info_shell->st_edit.minute[0] = heure_locale->tm_min;
}

char *get_cmd_home(i_s *info_shell)
{
    info_shell->st_edit.not_start_cmd = 0;
    if (isatty(0) == 1) {
        char *tmp = get_cmd_edition(info_shell);
        save_time(info_shell);
        return tmp;
    } else {
        char *tmp = get_cmd(info_shell);
        tmp = change_cmd_history_basic(info_shell, tmp);
        return tmp;
    }
    return "error";
}
