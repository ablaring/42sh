/*
** EPITECH PROJECT, 2022
** shell.c
** File description:
** Function : shell
*/

#include "struct_all.h"
#include "my.h"

int is_piped(char *cmd)
{
    for (int n = 1; cmd[n] != '\0'; n++) {
        if (cmd[n - 1] != '|' && cmd[n] == '|' && cmd[n + 1] != '|')
            return 1;
    }
    return 0;
}

void start_shell(i_s *info_shell, char *cmd)
{
    int error;
    error = and_or(info_shell, cmd);
    error_shell(info_shell, error);
    if (info_shell->st_redi.redir_type[1] == 1)
        reset_int_double(info_shell);
    if (info_shell->st_redi.redir_type[0] == 1)
        reset_int_single(info_shell);
    stop_redirect(info_shell);
    reset_redirect(info_shell);
}

void suite_shell(i_s *info_shell, char *cmd)
{
    cmd = my_cleaner(cmd);
    info_shell->st_pipe.nb_pipe = 0;
    info_shell->st_redi.err_redir = 0;
    if (redirect_error(info_shell, cmd) == 1) {
        return;
    } else {
        if (start_redirect(info_shell, cmd) == 84) {
            info_shell->return_value = 1;
            return;
        }
    }
    start_shell(info_shell, cmd);
}

int boucle_shell(i_s *info_shell)
{
    bool valid = true;
    sub_boucle_shell();
    char *cmd = get_cmd_home(info_shell);
    if (info_shell->stop == 1)
        return 0;
    if (info_shell->stop == 1 || cmd[0] == '\n' ||
    cleaner_and_patch(cmd) == 1 || info_shell->st_edit.not_start_cmd == 1)
        return 0;
    cmd = add_space_redirect(cmd);
    char **tab_cmd = my_str_to_word_array(cmd, ";\n");
    sub_sub_boucle_shell(info_shell, tab_cmd);
    tab_cmd = gestion_all(tab_cmd ,cmd, &valid, info_shell);
    for (int n = 0; valid && tab_cmd[n] != NULL; n++) {
        reset_redirect(info_shell);
        if (verif_espace(cmd) == 1)
            continue;
        suite_shell(info_shell, tab_cmd[n]);
    }
    return info_shell->return_value;
}

int shell(i_s *info_shell)
{
    while (info_shell->stop == 0) {
        while (info_shell->restart == 0 && info_shell->stop == 0)
            boucle_shell(info_shell);
        info_shell->restart = 0;
    }
    return 0;
}
