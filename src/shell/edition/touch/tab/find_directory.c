/*
** EPITECH PROJECT, 2022
** find_directories.c
** File description:
** Function : *
*/

#include "struct_all.h"
#include "my.h"

void sub_sub_find_directory(i_s *info_shell, glob_t glob_result,
    FilesResult result)
{
    result.num_files = glob_result.gl_pathc;
    result.files = (char**)malloc(result.num_files * sizeof(char*));
    for (int i = 0; i < result.num_files; i++) {
        char* path = glob_result.gl_pathv[i];
        char* file_name = strrchr(path, '/') + 1;
        struct stat st;
        if (stat(path, &st) == -1) {
            perror("stat");
            exit(EXIT_FAILURE);
        }
        size_t name_len = my_strlen(file_name);
        if (S_ISDIR(st.st_mode)) {
            result.files[i] = (char*)malloc((name_len + 2) * sizeof(char));
            snprintf(result.files[i], name_len + 2, "%s/", file_name);
        } else
            result.files[i] = strdup(file_name);
    }
    globfree(&glob_result);
    info_shell->st_edit.tmp_display_tab = result.files;
    info_shell->st_edit.size_tmp_display_tab = result.num_files;
}

int sub_find_directory(i_s *info_shell, glob_t glob_result,
    FilesResult result)
{
    if (glob_result.gl_pathc == 0) {
        return 2;
    } else {
        sub_sub_find_directory(info_shell, glob_result, result);
        return 0;
    }
}

int find_directory(i_s* info_shell, char* folder_name)
{
    FilesResult result = {NULL, 0};
    int is_absolute_path = (folder_name[0] == '/') ? 1 : 0;
    char* search_path = malloc(sizeof(char) * (my_strlen(folder_name) + 5));
    sprintf(search_path, "%s%s", (is_absolute_path ? "" : "./"), folder_name);
    glob_t glob_result;
    int glob_status = glob(search_path, 0, NULL, &glob_result);
    free(search_path);
    if (glob_status == GLOB_NOMATCH) {
        char* search_pattern = (char*)malloc(my_strlen(folder_name) + 5);
        sprintf(search_pattern, "%s%s*", (is_absolute_path ? "" : "./"),
            folder_name);
        glob(search_pattern, 0, NULL, &glob_result);
        free(search_pattern);
    }
    return sub_find_directory(info_shell, glob_result, result);
}
