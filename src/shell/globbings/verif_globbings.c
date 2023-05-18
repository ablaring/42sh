/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** verif_globbings
*/

#include "my.h"
#include "struct_all.h"

bool verif_glob(char * cmd)
{
    int c = 0;
    int len = strlen(cmd);
    for (; cmd[c] == ' '; c++);
    if (len == c)
        return false;
    char **tab_tmp = my_str_to_word_array(cmd, " ");
    if (strncmp(tab_tmp[0], "echo", 4) == 0)
        return false;
    for (int i = 0; cmd[i]; i++) {
        if (cmd[i] == '$')
            return false;
        if ((cmd[i] == '*' || cmd[i] == '?' || cmd[i] == '['))
            return true;
    }
    return false;
}
