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
sources/builtins/export_utils.c \
sources/builtins/shexit_exec.c \
sources/builtins/shexit.c \
sources/builtins/unset.c \
sources/env_export/env_list_init.c \
sources/env_export/env_list_utils.c \
sources/env_export/list_sort.c \
sources/env_export/string_utils.c \
sources/execution/execution_utils/cmd_utils.c \
sources/execution/execution_utils/count_cmds.c\
sources/execution/execution_utils/is_builtin.c\
sources/execution/execution_utils/pipe_maker.c \
sources/execution/redirection/append_redirect.c \
sources/execution/redirection/heredoc_redirect.c \
sources/execution/redirection/input_redirect.c\
sources/execution/redirection/output_redirect.c\
sources/execution/redirection/redirect_handler.c \
sources/execution/execute_all_cmds.c \
sources/execution/execute_builtin.c\
sources/parsing/token_split.c \
sources/parsing/first_expand.c \
sources/parsing/last_expand.c \
sources/parsing/parsing_utils.c \
sources/parsing/parsing_utils2.c \
sources/parsing/parsing_utils3.c \
sources/parsing/rereplace_redirect.c \
sources/env_export/env_list_utils2.c \
sources/shell_init/shell_init.c \

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
	$(CC) -o $(NAME) $(EXTRA_FLAGS)  $(OBJS) ./libft/libft.a

.PHONY: all clean fclean re valgrind funcheck funchecka

valgrind : $(NAME)
	valgrind --suppressions=valgrind_ignore_leaks.txt --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --show-mismatched-frees=yes --read-var-info=yes --track-fds=yes --trace-children=yes ./minishell

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
