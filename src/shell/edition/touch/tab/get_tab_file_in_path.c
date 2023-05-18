/*
** EPITECH PROJECT, 2022
** get_tab_file_in_path.c
** File description:
** Function : *
*/

#include "struct_all.h"
#include "my.h"

int end_get_tab_file_in_path(i_s *info_shell, char **files, size_t num_files,
    DIR *dir)
{
    closedir(dir);
    info_shell->st_edit.tmp_display_tab = files;
    info_shell->st_edit.size_tmp_display_tab = num_files;
    if (num_files == 0)
        return 2;
    return 0;
}

int get_tab_file_in_path(i_s* info_shell, char **files, size_t num_files)
{
    DIR* dir = opendir(info_shell->st_edit.tmp_tab);
    if (dir == NULL)
        return 2;
    struct dirent* dir_entry;
    while ((dir_entry = readdir(dir)) != NULL) {
        if (dir_entry->d_type == DT_REG) {
            num_files++;
            files = (char**)realloc(files, (num_files) * sizeof(char*));
            files[num_files - 1] = strdup(dir_entry->d_name);
        }
        if (dir_entry->d_type == DT_DIR) {
            num_files++;
            files = (char**)realloc(files, (num_files) * sizeof(char*));
            size_t name_len = my_strlen(dir_entry->d_name);
            files[num_files - 1] = (char*)malloc((name_len + 2) * sizeof(char));
            snprintf(files[num_files - 1], name_len + 2, "%s/",
                dir_entry->d_name);
        }
    }
    return end_get_tab_file_in_path(info_shell, files, num_files, dir);
}
