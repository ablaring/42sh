##
## EPITECH PROJECT, 2022
## makefile
## File description:
## 42SH
##

SRC 	=	src/function/mini_printf.c \
			src/function/my_put_nbr.c \
			src/function/my_putchar.c \
			src/function/my_putstr.c \
			src/function/my_compute_power_rec.c \
			src/function/my_revstr.c \
			src/function/my_str_to_word_array.c \
			src/function/my_getnbr.c \
			src/function/my_strcmp.c \
			src/function/my_strcp.c \
			src/function/my_strupper.c \
			src/function/my_strncmp.c \
			src/function/count_double_arr.c \
			src/function/my_str_isalpha.c \
			src/function/my_itoa.c \
			src/cmd_shell/my_cd.c \
			src/cmd_shell/my_cd2.c \
			src/cmd_shell/my_env.c \
			src/cmd_shell/my_unsetenv.c \
			src/cmd_shell/my_exit.c \
			src/cmd_shell/my_other/my_other.c \
			src/cmd_shell/my_other/function_my_other.c \
			src/cmd_shell/my_setenv/my_setenv.c \
			src/cmd_shell/my_setenv/edit_env.c \
			src/cmd_shell/my_setenv/new_env.c \
			src/cmd_shell/my_pwd.c \
			src/cmd_shell/my_echo.c \
			src/cmd_shell/my_execute.c \
			src/cmd_shell/my_history.c \
			src/shell/history_basic.c \
			src/shell/write_error.c \
			src/shell/verif_signal.c \
			src/shell/all_cleaner.c \
			src/shell/error_shell.c \
			src/shell/get_cmd.c \
			src/shell/path_separator.c \
			src/shell/start_cmd.c \
			src/shell/start_cmd_suite.c \
			src/shell/shell.c \
			src/shell/sub_boucle_shell.c \
			src/shell/function_shell.c \
			src/shell/redirect/redirect_utils.c \
			src/shell/redirect/redirect_add.c \
			src/shell/redirect/redirect_error.c \
			src/shell/redirect/redirect_cleaner.c \
			src/shell/redirect/redirect_pipe.c \
			src/shell/redirect/int_double.c \
			src/shell/redirect/int_single.c \
			src/shell/redirect/redirect.c \
			src/shell/pipe/main_pipe.c \
			src/shell/pipe/function_pipe.c \
			src/shell/pipe/pipe_error.c \
			src/shell/and_or.c \
			src/shell/sub_and_or.c \
			src/shell/get_or_and.c \
			src/shell/guillemets.c \
			src/shell/function_or_and.c \
			src/shell/edition/history.c \
			src/shell/edition/get_cmd.c \
			src/shell/edition/create_cmd_edition.c \
			src/shell/edition/touch_cmd_edition.c \
			src/shell/edition/moove.c \
			src/shell/edition/touch/delete.c \
			src/shell/edition/touch/suppr.c \
			src/shell/edition/touch/write.c \
			src/shell/edition/touch/flech_right.c \
			src/shell/edition/touch/flech_left.c \
			src/shell/edition/touch/flech_down.c\
			src/shell/edition/touch/flech_up.c \
			src/shell/edition/function_edition.c \
			src/shell/edition/reset_init_edition.c \
			src/shell/edition/home_edition.c \
			src/shell/edition/touch/tab/home_tab.c \
			src/shell/edition/touch/tab/get_display_tab.c \
			src/shell/edition/utils_history.c \
			src/cmd_shell/aliases/suite_aliases.c \
			src/cmd_shell/aliases/sub_aliases.c \
			src/cmd_shell/aliases/aliases.c \
			src/cmd_shell/aliases/unliases.c \
			src/shell/edition/touch/tab/utils_get_tab.c \
			src/shell/edition/touch/tab/get_tab_is_cmd.c \
			src/shell/edition/touch/tab/find_directory.c \
			src/shell/edition/touch/tab/display_tab.c \
			src/shell/edition/touch/tab/get_tab_file_in_path.c \
			src/shell/edition/touch/tab/utils_display_tab.c \
			src/shell/edition/touch/tab/auto_complection.c \
			src/shell/edition/touch/tab/utils_auto_complection.c \
			src/shell/env/stock_infoenv.c \
			src/shell/env/stock_suite.c \
			src/shell/env/check_ifvar.c \
			src/my_cleaner.c \
			src/cmd_shell/where/where.c \
			src/cmd_shell/which/which.c \
			src/function.c \
			src/init.c \
			src/init_sec.c \
			src/free.c \
			src/cwd.c \
			src/main.c \
			src/shell/globbings/gestion_globbings.c \
			src/shell/globbings/verif_globbings.c \
			src/function/my_strcat.c \
			src/shell/globbings/sub_handle_glob.c \
			src/shell/globbings/cat_glob.c \
			src/cmd_shell/where/sub_where.c \
			src/cmd_shell/my_echo2.c \
			src/cmd_shell/my_histo2.c \
			src/shell/sub_start_cmd.c \
			src/shell/redirect/redirect_error_suite.c \
			src/cmd_shell/my_setenv/sub_setenv.c \

OBJ	=	$(SRC:.c=.o)

CFLAGS = -Wall -Wextra -I ./include/ -g

NAME	=	42sh

all:	$(NAME)

$(NAME): $(OBJ)
	@echo -e "🔨 \033[0;32mCompile 42sh \033[0;30m🔨"
	gcc $(OBJ) $(CFLAGS) -o $(NAME) -lncurses
	@echo -e "✅ \033[0;31m42sh compiled ✅ \033[0m"

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

debug :
	gcc $(SRC) -Wall -Wextra -I include -o $(NAME) -g $(CFLAGS)

.PHONY:	all clean fclean re
