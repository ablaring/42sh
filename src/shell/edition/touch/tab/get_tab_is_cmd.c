/*
** EPITECH PROJECT, 2022
** get_tab_is_cmd.c
** File description:
** Function : *
*/

#include "struct_all.h"
#include "my.h"

char **get_path_in_env(i_s *info_shell)
{
    char *path = cherch_path(info_shell);
    if (path[0] == '8' && path[1] == '4' && path[2] == '\0')
        return NULL;
    int a = 0;
    for (int n = 5; path[n] != '\0'; n++) {
        path[a] = path[n];
        a++;
    }
    path[a] = '\0';
    int n = 0;
    for (; path[n] != '\0'; n++) {
        if (path[n] == ':')
        path[n] = ' ';
    }
    path[n] = '\0';
    char **result = my_str_to_word_array(path, " ");
    return result;
}

size_t sub_find_files_in_directory(i_s *info_shell, glob_t glob_result)
{
    int num_files = glob_result.gl_pathc;
    char** files = (char**)malloc(num_files * sizeof(char*));
    for (int i = 0; i < num_files; i++) {
        char* file_path = glob_result.gl_pathv[i];
        char* file_name = strrchr(file_path, '/');
        file_name = (file_name != NULL) ? file_name + 1 : file_path;
        size_t name_len = my_strlen(file_name);
        if (name_len > 0 && file_name[name_len - 1] == '/')
            file_name[name_len - 1] = '\0';
        files[i] = strdup(file_name);
    }
    globfree(&glob_result);
    int starting_index = info_shell->st_edit.size_tmp_display_tab;
    info_shell->st_edit.tmp_display_tab = (char**)realloc(
        info_shell->st_edit.tmp_display_tab, (starting_index + num_files)
            * sizeof(char*));
    for (int i = 0; i < num_files; i++)
        info_shell->st_edit.tmp_display_tab[starting_index + i] = files[i];
    info_shell->st_edit.size_tmp_display_tab += num_files;
    return starting_index;
}

int find_files_in_directory(i_s* info_shell, char* directory_path)
{
    char* search_pattern = (char*)malloc(my_strlen(directory_path) +
        my_strlen(info_shell->st_edit.tmp_tab) + 3);
    sprintf(search_pattern, "%s/%s*", directory_path,
        info_shell->st_edit.tmp_tab);
    glob_t glob_result;
    int glob_status = glob(search_pattern, GLOB_MARK, NULL, &glob_result);
    free(search_pattern);
    if (glob_status != 0) {
        globfree(&glob_result);
        return 2;
    } else {
        int starting_index =
            sub_find_files_in_directory(info_shell, glob_result);
        if (info_shell->st_edit.size_tmp_display_tab == starting_index)
            return 2;
        else
            return 0;
    }
}

int get_tab_is_cmd(i_s *info_shell)
{
    for (int n = 0; info_shell->st_edit.tmp_tab[n] != '\0'; n++)
        if (info_shell->st_edit.tmp_tab[n] == '/')
            return 2;
    char **directo_path = get_path_in_env(info_shell);
    for (int n = 0; directo_path[n] != NULL; n++)
        find_files_in_directory(info_shell, directo_path[n]);
    return 0;
}
