/*
** EPITECH PROJECT, 2023
** sub
** File description:
** glob
*/

#include "my.h"
#include "struct_all.h"

char *get_arg_env(i_s *info, int i)
{
    int len = 0;
    for (; info->env[i][len] != '='; len++);
    char *arg = malloc(sizeof(char) * len + 1);
    for (int b = 0; b < len; b++)
        arg[b] = info->env[i][b];
    arg[len] = '\0';
    return arg;
}

char *gestion_unsetenv_glob(i_s *inf, char *cmd)
{
    char **tab_tmp = my_str_to_word_array(cmd, " ");
    int b = get_lin_glob(tab_tmp);
    int res = 0;
    char *new_cmd = malloc(sizeof(char) * 10);
    strcpy(new_cmd, "unsetenv ");
    for (int i = 0; inf->env[i]; i++) {
        res = fnmatch(tab_tmp[b], inf->env[i], 0);
        if (res == 0) {
            new_cmd = realloc(new_cmd, sizeof(char) * (strlen(new_cmd)
            + strlen(get_arg_env(inf, i)) + 2));
            strcat(new_cmd, get_arg_env(inf, i));
            strcat(new_cmd, " ");
        }
    }
    return new_cmd;
}

void handle_len_glob(int i, int j, int len, char **tab_tmp)
{
    for (j = i; j < len - 1; j++)
        tab_tmp[j] = tab_tmp[j + 1];
}

void error_handling_glob(char *cmd, int nb_find, char *glob, bool *valid)
{
    if (strncmp(cmd, "cd", 2) == 0 && nb_find > 1) {
        dprintf(2, "%s: Ambiguous.\n", glob);
        (*valid) = false;
        return;
    }
    (*valid) = true;
}
