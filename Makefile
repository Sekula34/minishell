SOURCES = sources/main.c \
sources/builtins/cd_exec.c\
sources/builtins/cd_utils.c \
sources/builtins/cd.c \
sources/builtins/echo_exec.c\
sources/builtins/echo.c \
sources/builtins/env_exec.c \
sources/builtins/pwd_exec.c\
sources/builtins/pwd.c \
sources/builtins/env.c \
sources/builtins/export.c \
sources/builtins/export_exec.c \
sources/builtins/export_utils.c \
sources/builtins/shexit_exec.c \
sources/builtins/shexit.c \
sources/builtins/unset_exec.c\
sources/builtins/unset.c \
sources/env_export/env_list_init.c \
sources/env_export/env_list_utils.c \
sources/env_export/list_sort.c \
sources/env_export/string_utils.c \
sources/env_export/string_utils2.c \
sources/execution/execution_utils/child_executor.c \
sources/execution/execution_utils/child_multi_exec_utils.c \
sources/execution/execution_utils/child_multi_exec.c \
sources/execution/execution_utils/clear_mini_env.c \
sources/execution/execution_utils/close_all_pipes.c \
sources/execution/execution_utils/cmd_utils.c \
sources/execution/execution_utils/count_cmds.c\
sources/execution/execution_utils/export_exit_status.c \
sources/execution/execution_utils/is_builtin.c\
sources/execution/execution_utils/is_minishell.c\
sources/execution/execution_utils/pipe_maker.c \
sources/execution/execution_utils/set_cmd_path.c \
sources/execution/execution_utils/set_mini_env.c \
sources/execution/multiple_cmd/execute_multiple_cmd.c \
sources/execution/redirection/append_redirect.c \
sources/execution/redirection/heredoc_parent_prepare.c \
sources/execution/redirection/heredoc_redirect.c \
sources/execution/redirection/input_redirect.c\
sources/execution/redirection/output_redirect.c\
sources/execution/redirection/redirect_handler.c \
sources/execution/execute_all_cmds.c \
sources/execution/execute_builtin.c\
sources/execution/execute_minishell.c \
sources/execution/execute_one_command.c\
sources/execution/execute_original_cmd.c \
sources/parsing/token_split.c \
sources/parsing/token_split2.c \
sources/parsing/classifying_tokens2.c \
sources/parsing/classifying_tokens3.c \
sources/parsing/first_expand.c \
sources/parsing/first_expand2.c \
sources/parsing/first_expand3.c \
sources/parsing/last_expand.c \
sources/parsing/last_expand2.c \
sources/parsing/parsing_utils.c \
sources/parsing/parsing_utils2.c \
sources/parsing/parsing_utils3.c \
sources/parsing/rereplace_redirect.c \
sources/parsing/classifying_tokens.c \
sources/parsing/split_pipes.c \
sources/parsing/redirect_utils.c \
sources/parsing/cmd_utils.c \
sources/parsing/free_utils.c \
sources/parsing/free_utils2.c \
sources/parsing/syntax_check.c \
sources/parsing/syntax_check2.c \
sources/parsing/rm_quotes_from_tokens.c \
sources/parsing/convert_fake_redirect.c \
sources/parsing/heredoc_expand.c \
sources/parsing/parsing.c \
sources/env_export/env_list_utils2.c \
sources/shell_init/shell_init.c \
sources/shell_init/shell_clear.c \
sources/signals/signal_functions.c \
sources/signals/signals.c \
sources/get_next_line/get_next_line.c \
sources/get_next_line/get_next_line_utils.c \
sources/main_utils.c

HEADERS = headers/builtin.h \
headers/data_types.h \
headers/envexport.h \
headers/minishel.h \
headers/shell_init.h \

CC = cc 

COMPILER_FLAGS = -Wall -Wextra -Werror -g

EXTRA_FLAGS = -lreadline

NAME = minishell

OBJS := $(SOURCES:%.c=%.o)

%.o: %.c
	$(CC) $(COMPILER_FLAGS) -c $< -o $@


$(NAME): $(OBJS) $(HEADERS)
	cd libft && $(MAKE) && $(MAKE) bonus
	$(CC) -o $(NAME)  $(OBJS) ./libft/libft.a $(EXTRA_FLAGS) 

.PHONY: all clean fclean re valgrind funcheck funchecka

valgrind : $(NAME)
	valgrind --suppressions=valgrind_ignore_leaks.txt --leak-check=full --show-leak-kinds=all --track-fds=yes --trace-children=yes ./minishell

funcheck : $(NAME)
	funcheck ./$(NAME)

funchecka : $(NAME)
	funcheck -a ./$(NAME)

all: $(NAME)

clean:
	cd libft && $(MAKE) fclean 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
