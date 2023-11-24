NAME = minishel

SRCS = *.c

OBJS = $(SRCS:.c=.o)

CC = cc
RM = rm -rf

CFLAGS = -g
RLFLAGS = -lreadline

all: $(NAME)

$(NAME): $(OBJS)
			$(CC) $(OBJS) $(CFLAGS) $(RLFLAGS) -o minishel

clean:
			$(RM) $(OBJS)

fclean:	clean
			$(RM) $(NAME)

re: 	fclean all

.phony: all, clean, fclean, re

