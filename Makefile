SOURCES = sources/main.c \
sources/builtins/echo.c \
sources/builtins/pwd.c \
sources/env_export/string_utils.c

HEADERS = headers/builtin.h \
headers/envexport.h \
headers/minishel.h 

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
