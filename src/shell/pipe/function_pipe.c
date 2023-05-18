/*
** EPITECH PROJECT, 2022
** pipe_error.c
** File description:
** Function : pipe_error
*/

#include "struct_all.h"
#include "my.h"

void all_close_pipe(i_s *info_shell)
{
    for (int n = 0; n <= info_shell->st_pipe.nb_pipe; n++) {
        close(info_shell->st_pipe.pi[n][0]);
        close(info_shell->st_pipe.pi[n][1]);
    }
}

int init_pipe(i_s *info_shell)
{
    info_shell->st_pipe.pos = 0;
    info_shell->st_pipe.pos_max = info_shell->st_pipe.nb_pipe;

    info_shell->st_pipe.pi = malloc(sizeof(int*) *
        (info_shell->st_pipe.nb_pipe + 2));
    info_shell->st_pipe.waitpid = malloc(sizeof(int) *
        (info_shell->st_pipe.nb_pipe + 3));
    int n = 0;
    for (; n <= info_shell->st_pipe.nb_pipe; n++) {
        info_shell->st_pipe.pi[n] = malloc(sizeof(int) * 3);
        if (pipe(info_shell->st_pipe.pi[n]) == -1) {
            info_shell->return_value = 1;
            write_error("Error pipe\n");
            return -1;
        }
        info_shell->st_pipe.waitpid[n] = -1;
    }
    return 0;
}

void piped(i_s *info_shell)
{
    if (info_shell->st_pipe.nb_pipe == 0)
        return;
    int pos = info_shell->st_pipe.pos;
    int pos_max = info_shell->st_pipe.pos_max;
    if (pos < pos_max) {
        dup2(info_shell->st_pipe.pi[pos][1], STDOUT_FILENO);
        close(info_shell->st_pipe.pi[pos][1]);
    }
    if (pos != 0) {
        dup2(info_shell->st_pipe.pi[pos - 1][0], STDIN_FILENO);
        close(info_shell->st_pipe.pi[pos - 1][0]);
    }
    all_close_pipe(info_shell);
}

void waitpid_pipe(i_s *info_shell)
{
    for (int n = 0; n <= info_shell->st_pipe.nb_pipe; n++) {
        verif_signal(info_shell, info_shell->st_pipe.waitpid[n]);
    }
}

int pipe_error(char *cmd, i_s *info_shell)
{
    int n = 0;
    for (; cmd[n] != '\0' && cmd[n] != '>' && cmd[n] != '<'; n++);
    if (cmd[n] == '\0')
        return 0;
    int i = n + 1;
    for (; cmd[i] != '\0' && cmd[i] != '|'; i++);
    if (cmd[i] == '|') {
        info_shell->return_value = 1;
        return write_error_rep("Ambiguous output redirect.\n");
    }
    return 0;
}
