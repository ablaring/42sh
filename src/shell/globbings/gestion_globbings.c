/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** gestion_globbings
*/

#include "my.h"
#include "struct_all.h"
#include <glob.h>

void print_error_glob(char *cmd, bool *valid)
{
    char **tab_tmp = my_str_to_word_array(cmd, " ");
    bool left = false;
    bool right = false;
    for (int i = 0; cmd[i]; i++) {
        if (cmd[i] == '[')
            left = true;
        if (cmd[i] == ']')
            right = true;
        if (cmd[i] == '[' && cmd[i + 1] && cmd[i + 1] != ']') {
            dprintf(2, "%s: cannot access '%s': No such file or directory\n",
            tab_tmp[0], tab_tmp[get_lin_glob(tab_tmp)]);
            return;
        }
        if (left && right == false && tab_tmp[1] == NULL) {
            dprintf(2, "[: missing ’]’\n");
            return;
        }
    }
    (*valid) = false;
    dprintf(2, "%s: No match.\n", tab_tmp[0]);
}

int get_lin_glob(char ** tab_tmp)
{
    int b = 0;
    for (; tab_tmp[b]; b++) {
        if (verif_glob(tab_tmp[b]))
            break;
    }
    return b;
}

void del_glob_line(char** tab_tmp)
{
    int i = 0;
    int j = 0;
    int len = 0;
    for (;tab_tmp[len]; len++);
    for (i = 0; i < len; i++) {
        if (strchr(tab_tmp[i], '*') || strchr(tab_tmp[i], '?') ||
            strchr(tab_tmp[i], '[') || strchr(tab_tmp[i], ']')) {
            handle_len_glob(i, j, len, tab_tmp);
            len--;
            tab_tmp[len] = NULL;
            i--;
        }
    }
}

char *gestion_star(char *cmd, bool *valid, i_s *info_shell)
{
    glob_t globbuf;
    char *tmp = NULL;
    char **tab_tmp = my_str_to_word_array(cmd, " ");
    int b = get_lin_glob(tab_tmp);
    char *save = tab_tmp[b];
    if (strncmp(cmd, "unsetenv", 8) == 0)
        return gestion_unsetenv_glob(info_shell, cmd);
    else
        glob(tab_tmp[b], 0, NULL, &globbuf);
    if (globbuf.gl_pathc == 0 || strncmp(cmd, "/bin/*", 6) == 0) {
        print_error_glob(cmd, valid);
        return NULL;
    }
    del_glob_line(tab_tmp);
    tmp = cat_cmd(tab_tmp, globbuf, tmp);
    globfree(&globbuf);
    error_handling_glob(tmp, globbuf.gl_pathc, save, valid);
    return tmp;
}

char ** gestion_all(char **tab_cmd, char *cmd, bool *valid, i_s *info_shell)
{
    if (verif_glob(cmd))
        tab_cmd[get_lin_glob(tab_cmd)] = gestion_star(cmd, valid, info_shell);
    return tab_cmd;
}
