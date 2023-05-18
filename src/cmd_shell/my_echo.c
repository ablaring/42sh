/*
** EPITECH PROJECT, 2022
** my_echo.c
** File description:
** Function : my_echo
*/

#include "struct_all.h"
#include "my.h"

void sub_get_term(i_s *info_shell, char **tab_term)
{
    if (info_shell->st_pipe.nb_pipe == 0)
        printf("%s\n", tab_term[1]);
    else
        dprintf(info_shell->st_pipe.pi[info_shell->st_pipe.pos][1],
            "%s\n", tab_term[1]);
}

void get_term_info(i_s *info_shell)
{
    char **tab_term = NULL;
    for (int i = 0; info_shell->env[i]; i++) {
        if (my_strncmp(info_shell->env[i], "TERM", 4) == 0) {
            tab_term = my_str_to_word_array(info_shell->env[i], "=");
            sub_get_term(info_shell, tab_term);
            break;
        }
    }
}

void supprimer_caractere(i_s *info_shell, char *str, int position)
{
    int longueur = strlen(str);
    if (position >= longueur || position < 0) {
        if (info_shell->st_pipe.nb_pipe == 0)
            printf("ERROR: Position invalide.\n");
        else
            dprintf(info_shell->st_pipe.pi[info_shell->st_pipe.pos][1],
                "ERROR: Position invalide.\n");
        return;
    }
    for (int i = position; i < longueur - 1; i++) {
        str[i] = str[i + 1];
    }
    str[longueur - 1] = '\0';
}

char *clean_echo(char *cmd, int nb)
{
    int n = 0;
    for (int a = nb; cmd[a] != '\0'; a++) {
        cmd[n] = cmd[a];
        n++;
    }
    cmd[n] = '\0';
    return cmd;
}

int my_echo(i_s *info_shell, char *cmd)
{
    info_shell->st_cond.cmd_good = 1;
    cmd = patch_echo_appostro(info_shell, cmd);
    char **tab = my_str_to_word_array(info_shell->st_edit.list_cmd
        [info_shell->st_edit.pos_history], " ");
    if (tab[1] == NULL)
        return write_error("\n");
    if (tab[2] != NULL && my_strcmp(tab[1], "-n") == 0) {
        cmd = clean_echo(cmd, 8);
        mini_printf("%s", cmd);
        return 0;
    }
    if (tab[1] != NULL && (my_strcmp(tab[1], "$TERM") == 0
    || my_strcmp(tab[1], "$term")) == 0)
        get_term_info(info_shell);
    if (quotes_right(cmd) == true)
        dprintf(2, "Unmatched '%s'.\n", "\"");
    else
        classic_echo(cmd, info_shell, tab);
    return 0;
}
