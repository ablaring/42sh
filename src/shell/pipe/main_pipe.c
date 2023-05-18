/*
** EPITECH PROJECT, 2022
** main_pipe.c
** File description:
** Function : main_pipe
*/

#include "struct_all.h"
#include "my.h"

void reload_dup2(i_s *info_shell, int n)
{
    dup2(info_shell->st_pipe.old, STDIN_FILENO);
    close(info_shell->st_pipe.old);
    dup2(info_shell->st_pipe.old_out, STDOUT_FILENO);
    close(info_shell->st_pipe.old_out);
    if (n == 0)
        info_shell->st_pipe.pos++;
}

int finish_main_pipe(i_s *info_shell)
{
    reload_dup2(info_shell, 1);
    all_close_pipe(info_shell);
    while (wait(NULL) != -1);
    waitpid_pipe(info_shell);
    return 0;
}

void get_out_in(i_s *info_shell)
{
    info_shell->st_pipe.old = dup(STDIN_FILENO);
    info_shell->st_pipe.old_out = dup(STDOUT_FILENO);
}

void get_pos_max_pipe(i_s *info_shell, char *cmd)
{
    info_shell->st_pipe.nb_pipe = 0;
    for (int n = 0; cmd[n] != '\0'; n++)
        if (cmd[n] == '|')
            info_shell->st_pipe.nb_pipe++;
}

int main_pipe(i_s *info_shell, char *cmd)
{
    if (error_pipe(cmd, info_shell) == 1) return 1;
    get_pos_max_pipe(info_shell, cmd);
    cmd = redirect_pipe(info_shell, cmd);
    if (init_pipe(info_shell) == -1)
        return 0;
    get_out_in(info_shell);
    if (start_cmd(info_shell, cmd) == 84)
        return (info_shell->st_cond.cmd_good = 0);
    reload_dup2(info_shell, 0);
    while (info_shell->st_pipe.pos <= info_shell->st_pipe.pos_max) {
        close(info_shell->st_pipe.pi[info_shell->st_pipe.pos - 1][1]);
        get_out_in(info_shell);
        if (start_cmd(info_shell,
            info_shell->st_pipe.tab_pipe[info_shell->st_pipe.pos - 1]) == 84) {
            info_shell->st_cond.cmd_good = 0;
            return 0;
        }
        reload_dup2(info_shell, 0);
    }
    return finish_main_pipe(info_shell);
}
