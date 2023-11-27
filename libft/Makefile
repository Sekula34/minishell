NAME = libft.a

COMPILER = cc

COMP_FLAGS = -Wall -Wextra -Werror

SRCS = ft_atoi.c \
ft_bzero.c \
ft_calloc.c \
ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
ft_isdigit.c \
ft_isprint.c \
ft_itoa.c \
ft_memchr.c \
ft_memcmp.c \
ft_memcpy.c \
ft_memmove.c \
ft_memset.c \
ft_putchar_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_putstr_fd.c \
ft_split.c \
ft_strchr.c \
ft_strdup.c \
ft_striteri.c \
ft_strjoin.c \
ft_strlcat.c \
ft_strlcpy.c \
ft_strlen.c \
ft_strmapi.c \
ft_strncmp.c \
ft_strnstr.c \
ft_strrchr.c \
ft_strtrim.c \
ft_substr.c \
ft_tolower.c \
ft_toupper.c \
printf/ft_bzero.c \
printf/ft_calloc.c \
printf/ft_putchar_fd.c \
printf/ft_putnbr_fd.c \
printf/ft_putstr_fd.c \
printf/ft_strlcpy.c \
printf/ft_strlen.c \
printf/ft_toupper.c  \
printf/printc.c \
printf/printdi.c \
printf/printp.c \
printf/prints.c \
printf/printu.c \
printf/printx.c \
printf/putunbr.c \
printf/ft_printf.c

BONUS_SRC = ft_lstnew.c \
ft_lstadd_front.c\
ft_lstsize.c \
ft_lstlast.c \
ft_lstadd_back.c \
ft_lstdelone.c \
ft_lstclear.c \
ft_lstiter.c \
ft_lstmap.c

BONUS_OBJS := $(BONUS_SRC:%.c=%.o)

OBJS := $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS) $^

%.o: %.c libft.h 
	$(COMPILER) $(COMP_FLAGS) -c $< -o $@ 

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(OBJS) $(BONUS_OBJS)
	ar -rcs $(NAME) $(OBJS) $(BONUS_OBJS) 

.PHONY: clean fclean re all bonus
