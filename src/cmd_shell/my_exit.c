/*
** EPITECH PROJECT, 2022
** my_exit.c
** File description:
** Function : my_exit
*/

#include "struct_all.h"
#include "my.h"

static int test_exit_value(i_s *info_shell, char **tab)
{
    int a = 0;
    for (; tab[a] != NULL; a++);
    if (a == 1) {
        info_shell->return_value = 0;
        info_shell->stop = 1;
        mini_printf("exit\n");
    }
    return a;
}

int error_exit(i_s *info_shell, int check, char **tab, int a)
{
    if (check == 1 || a > 2) {
        if (info_shell->st_pipe.nb_pipe == 0)
            printf("%s: Expression Syntax.\n", tab[0]);
        else
            dprintf(info_shell->st_pipe.pi[info_shell->st_pipe.pos][1],
                "%s: Expression Syntax.\n", tab[0]);
        return info_shell->return_value = 1;
    }
    if (info_shell->st_pipe.nb_pipe == 0)
        printf("exit\n");
    else
        dprintf(info_shell->st_pipe.pi[info_shell->st_pipe.pos][1],
            "exit\n");
    return (0);
}

int my_exit_suite(i_s *info_shell, int check, char **tab, int a)
{
    if (tab[1][0] == '-' && my_strlen(tab[1]) == 1) {
        printf("%s: Expression Syntax.\n", tab[0]);
        info_shell->return_value = 1;
        return -198;
    }
    if ((a == 2 && check == 0) || (a == 2 && check == 1 && tab[1][0] == '-')) {
        printf("exit\n");
        info_shell->stop = 1;
        return info_shell->return_value = my_getnbr(tab[1]);
    }
    if ((check > 1)) {
        printf("%s: Expression Syntax.\n", tab[0]);
        return -198;
    }
    if (error_exit(info_shell, check, tab, a) == 1)
        return -198;
    return 0;
}

int my_exit(i_s *info_shell, char *cmd)
{
    if (cmd[(strlen(cmd) - 1)] == ' ')
        cmd[(strlen(cmd) - 1)] = '\0';
    char **tab = my_str_to_word_array(cmd, " ");
    int check = 0;
    int a = 0;
    info_shell->st_cond.cmd_good = 1;
    info_shell->stop = 1;
    if (cmd[0] != 'e')
        return 0;
    if ((a = test_exit_value(info_shell, tab)) == 1)
        return 1;
    for (int i = 0; tab[1][i] != '\0'; i++)
        if (tab[1][i] > 57 || tab[1][i] < 48)
            check++;
    if (tab[1][0] == '-' && check > 1) {
        printf("%s: Badly formed number.\n", tab[0]);
        return info_shell->return_value = 1;
    }
    my_exit_suite(info_shell, check, tab, a);
    return info_shell->return_value;
}
