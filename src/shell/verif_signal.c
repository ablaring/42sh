/*
** EPITECH PROJECT, 2022
** verif_signal.c
** File description:
** Function : verif_signal
*/

#include "struct_all.h"
#include "my.h"

void sig_error(i_s *info_shell, int status)
{
    if (info_shell->return_value == 139)
        write_error("Segmentation fault");
    if (info_shell->return_value == 136)
        write_error("Floating exception");
    if (info_shell->return_value == 134)
        write_error("Illegal instruction");
    if (WCOREDUMP(status))
        write_error(" (core dumped)");
    if (info_shell->return_value == 139 || info_shell->return_value == 136 ||
        info_shell->return_value == 134)
        write_error("\n");
}

int display_error_signal(i_s *info_shell, int status)
{
    info_shell->return_value = WEXITSTATUS(status);
    if (WIFSIGNALED(status) == true) {
        write_error(strsignal(WTERMSIG(status)));
        if (WCOREDUMP(status) == true)
            write_error(" (core dumped)");
        return write_error("\n");
    }
    if (SIGFPE == status) {
        write_error("Floating exception\n");
        if (WCOREDUMP(status) == true)
            write_error(" (core dumped)");
        return write_error("\n");
    }
    if (SIGABRT == status)
        return write_error("Abort (core dumped)\n");
    if (WIFSTOPPED(status) == true)
        return write_error(strsignal(WSTOPSIG(status)));
    info_shell->st_cond.cmd_good = 1;
    return 0;
}

int verif_signal(i_s *info_shell, int pid)
{
    if (pid == -1)
        return 0;
    int status;
    if (waitpid(pid, &status, 0) == -1)
        return 0;
    info_shell->st_cond.cmd_good = 0;
    return display_error_signal(info_shell, status);
}
