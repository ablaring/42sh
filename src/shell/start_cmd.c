/*
** EPITECH PROJECT, 2022
** shell.c
** File description:
** Function : shell
*/

#include "struct_all.h"
#include "my.h"

char *one_word(char *cmd)
{
    int tmp = 0;
    while (cmd[tmp] != ' ' && cmd[tmp] != '\0' && cmd != NULL)
        tmp++;
    char *result = malloc(sizeof(char) * (tmp + 2));
    for (int n = 0; n <= tmp; n++)
        result[n] = cmd[n];
    result[tmp] = ' ';
    result[tmp + 1] = '\0';
    return result;
}

int start_buildin(i_s *info_shell, char *one_arg, char *cmd)
{
    int (*funct[12])(i_s *, char *) = {&my_cd, &my_env, &my_exit, &my_setenv,
    &my_unsetenv, &my_pwd, &my_echo, &my_alias, &my_unalias, &where, &which,
    &my_history};
    char *flags[12] = {"cd ", "env ", "exit ", "setenv ", "unsetenv ", "pwd ",
    "echo ", "alias ", "unalias ", "where ", "which ", "history "};
    for (int n = 0; n < 12; n++) {
        info_shell->nb_buildin = n;
        if (my_strcmp(flags[n], one_arg) == 0)
            return funct[n](info_shell, cmd);
    }
    return -98;
}

int start_cmd_suite_de_la_suite(i_s *info_shell, char *cmd, char *one_arg)
{
    if (my_execute(info_shell, cmd) == 1)
        return 0;
    if (my_other(info_shell, cmd, one_arg) == -1) {
        double_write(one_arg, ": Command not found.\n");
        info_shell->return_value = 1;
        info_shell->st_cond.cmd_good = 0;
    }
    return (1);
}

int start_cmd(i_s *info_shell, char *cmd)
{
    int tmp = start_cmd_debut(info_shell, &cmd);
    if (tmp == 0 || tmp == 1){
        info_shell->return_value = tmp;
        return tmp;
    }
    char *one_arg = one_word(cmd);
    if (info_shell->is_single == 0)
        check_allias(&one_arg, &cmd, info_shell);
    tmp = start_buildin(info_shell, one_arg, cmd);
    star_cmd_suite(info_shell, tmp);
    if (tmp != -98){
        info_shell->return_value = tmp;
        return tmp;
    }
    if (info_shell->stop == 1 || my_strlen(cmd) == 0)
        return 0;
    one_arg[(my_strlen(one_arg) - 1)] = '\0';
    if (my_execute(info_shell, cmd) == 1) return 0;
    start_cmd_end(info_shell, cmd, one_arg);
    return 0;
}
