/*
** EPITECH PROJECT, 2022
** my_env.c
** File description:
** Function : my_env
*/

#include "struct_all.h"
#include "my.h"

char *env_one_arg(char *cmd, int deb)
{
    int n = 0;
    for (int a = deb; cmd[a] != '\0'; a++) {
        cmd[n] = cmd[a];
        n++;
    }
    cmd[n] = '\0';
    return cmd;
}

static char *good_arg_env(char *cmd)
{
    char *result = malloc(sizeof(char) * (my_strlen(cmd) + 5));
    char *f_name = "unsetenv ";
    for (int a = 0; a < 9; a++)
        result[a] = f_name[a];
    char *arg = env_one_arg(cmd, 7);
    int a = 9;
    int n = 0;
    for (; arg[n] != '\0'; n++) {
        result[a] = arg[n];
        a++;
    }
    result[a] = '\0';
    return result;
}

void sub_disp_err(i_s *info_shell, char *cmd)
{
    if (cmd[3] == ' ' && cmd[4] == '-' && cmd[5] != '\0') {
        if (info_shell->st_pipe.nb_pipe == 0)
            dprintf(2, "env: invalid option -- '%s'\n", cmd);
        else
            dprintf(info_shell->st_pipe.pi[info_shell->st_pipe.pos][1],
                "env: invalid option -- '%s'\n", cmd);
    } else {
        if (info_shell->st_pipe.nb_pipe == 0)
            dprintf(2, "env: '%s':No such file or directory\n",
                env_one_arg(cmd, 4));
        else
            dprintf(info_shell->st_pipe.pi[info_shell->st_pipe.pos][1],
                "env: '%s':No such file or directory\n", env_one_arg(cmd, 4));
        info_shell->return_value = 127;
    }
}

int display_error_my_env(i_s *info_shell, char *cmd)
{
    if ((cmd[3] == ' ' && cmd[4] == '-' && cmd[5] == '0' && cmd[6] == '\0')
    || (cmd[3] == ' ' && cmd[4] == '-' && cmd[5] == '-' && cmd[6] == 'n' &&
    cmd[7] == 'u' && cmd[8] == 'l' && cmd[9] == 'l' && cmd[10] == '\0')) {
        for (int n = 0; info_shell->env[n] != NULL; n++)
            mini_printf("%s", info_shell->env[n]);
        mini_printf("\n");
    }
    if (cmd[3] == ' ' && cmd[4] == '-' && cmd[5] == 'u' && cmd[6] == '\0') {
        if (info_shell->st_pipe.nb_pipe == 0)
            dprintf(2, "env: option requires an argument -- 'u'\n");
        else
            dprintf(info_shell->st_pipe.pi[info_shell->st_pipe.pos][1],
                "env: option requires an argument -- 'u'\n");
    }
    if (cmd[3] == ' ' && cmd[4] == '-' && cmd[5] == 'u' && cmd[6] == ' ')
        return my_unsetenv(info_shell, good_arg_env(cmd));
    sub_disp_err(info_shell, cmd);
    return 0;
}

int my_env(i_s *info_shell, char *cmd)
{
    if (cmd[(strlen(cmd) - 1)] == ' ')
        cmd[(strlen(cmd) - 1)] = '\0';
    if (cmd[3] == '\0') {
        for (int n = 0; n < info_shell->size_env; n++) {
            (info_shell->st_pipe.nb_pipe == 0 ?
            printf("%s\n", info_shell->env[n]) :
            dprintf(info_shell->st_pipe.pi[info_shell->st_pipe.pos][1],
            "%s\n", info_shell->env[n])
        );
        }
        info_shell->return_value = 0;
        return 0;
    }
    info_shell->st_cond.cmd_good = 1;
    return display_error_my_env(info_shell, cmd);
}
