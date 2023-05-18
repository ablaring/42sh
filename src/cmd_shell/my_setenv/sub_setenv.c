/*
** EPITECH PROJECT, 2022
** shell.c
** File description:
** Function : shell
*/

#include "struct_all.h"
#include "my.h"

static char *clean_setenv(char *the_cmd, char **cmd, int nb_arg)
{
    int size_max;
    if (nb_arg == 2)
        size_max = my_strlen(cmd[1]) + 2;
    else
        size_max = my_strlen(cmd[1]) + my_strlen(the_cmd) + 2;
    char *result = malloc(sizeof(char) * (size_max));
    int n = 0;
    for (; cmd[1][n] != '\0'; n++)
        result[n] = cmd[1][n];
    result[n] = '=';
    if (nb_arg == 2) {
        result[n + 1] = '\0';
    } else {
        n++;
        for (int a = 0; cmd[2][a] != '\0'; a++) {
            result[n] = cmd[2][a];
            n++;
        }
        result[n] = '\0';
    } return result;
}

int my_setenv_suite(i_s *info_shell, char *cmd)
{
    char **tab_cmd = my_str_to_word_array(cmd, " ");
    int pos = cherch_arg_env(info_shell, tab_cmd[1]);
    if (pos == -1)
        return (new_env(info_shell, clean_setenv(cmd, tab_cmd, nb_arg(cmd))));
    else
        return (edit_env(info_shell, tab_cmd, nb_arg(cmd), pos));
}
