/*
** EPITECH PROJECT, 2023
** echo
** File description:
** 2
*/

#include "struct_all.h"
#include "my.h"

char *patch_echo_appostro(i_s *info_shell, char *cmd)
{
    for (int n = 0; cmd[n] != '\0'; n++){
        if (cmd[n] == '\'')
            supprimer_caractere(info_shell, cmd, n);
    }
    return cmd;
}

char *trim_right(char *s)
{
    if (s == NULL || *s == '\0')
        return s;
    char *back = s + strlen(s);
    while (isspace(*--back));
    *(back + 1) = '\0';
    return s;
}
