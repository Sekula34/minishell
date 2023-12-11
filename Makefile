SOURCES = sources/main.c \
sources/builtins/cd_utils.c \
sources/builtins/cd.c \
sources/builtins/echo.c \
sources/builtins/pwd.c \
sources/builtins/env.c \
sources/builtins/export.c \
sources/builtins/export_utils.c \
sources/builtins/shexit.c \
sources/builtins/unset.c \
sources/env_export/env_list_init.c \
sources/env_export/env_list_utils.c \
sources/env_export/list_sort.c \
sources/env_export/string_utils.c \
sources/execution/execution_utils/count_cmds.c\
sources/execution/execution_utils/is_builtin.c\
sources/execution/execution_utils/pipe_maker.c \
sources/execution/execute_all_cmds.c \
sources/parsing/token_split.c \
sources/parsing/first_expand.c \
sources/parsing/last_expand.c \
sources/parsing/parsing_utils.c \
sources/parsing/parsing_utils2.c \
sources/parsing/parsing_utils3.c \
sources/parsing/rereplace_redirect.c \
sources/env_export/env_list_utils2.c

HEADERS = headers/builtin.h \
headers/data_types.h \
headers/envexport.h \
headers/minishel.h \

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

.PHONY: all clean fclean re

all: $(NAME)

clean:
	cd libft && $(MAKE) fclean 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
