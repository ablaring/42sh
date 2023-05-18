/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** cat_glob
*/

#include "my.h"
#include "struct_all.h"

void cat_pipe_glob(char ** tab_tmp, char *tmp)
{
    int b = 0;
    bool piped = false;
    for (; tab_tmp[b]; b++) {
        if (strchr(tab_tmp[b],'|')) {
            piped = true;
            break;
        }
    }
    if (piped) {
        for (;tab_tmp[b]; b++) {
            tmp = strcat(tmp, tab_tmp[b]);
            tmp = strcat(tmp, " ");
        }
    }
}

char * sub_cat_cmd(char * tmp, glob_t globbuf, int *len)
{
    for (int i = 0; globbuf.gl_pathv[i]; i++) {
        tmp = realloc(tmp, (*len) + strlen(globbuf.gl_pathv[i]) + 1);
        tmp = strcat(tmp, globbuf.gl_pathv[i]);
        (*len) = strlen(tmp);
        tmp = realloc(tmp, (*len) + strlen(" ") + 10);
        tmp = strcat(tmp, " ");
        (*len) = strlen(tmp);
    }
    return tmp;
}

char *cat_cmd(char ** tab_tmp, glob_t globbuf, char *tmp)
{
    tmp = strdup("\0");
    int len = strlen(tmp);
    for (int i = 0; tab_tmp[i] && !strchr(tab_tmp[i],'|'); i++) {
        tmp = realloc(tmp, len + strlen(tab_tmp[i]) + 1);
        tmp = strcat(tmp, tab_tmp[i]);
        len = strlen(tmp);
        tmp = realloc(tmp, len + strlen(" ") + 1);
        tmp = strcat(tmp, " ");
        len = strlen(tmp);
    }
    tmp = sub_cat_cmd(tmp, globbuf, &len);
    tmp[len] = '\0';
    cat_pipe_glob(tab_tmp, tmp);
    return tmp;
}
