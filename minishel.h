#ifndef MINISHEL
#define MINISHEL
#define NAME "minishel: "



typedef struct s_vars
{
	char				*key;
	char 				*value;
	struct s_vars 		*next;
}	t_vars;

typedef struct s_redirect
{
	char 				*redirect;
	struct s_redirect	*next;
}	t_redirect;

typedef struct s_cmd
{
	char				*path;
	char				**args;
	t_redirect			*redirect_lst;
	struct s_cmd		*next;

}	t_cmd;

typedef struct s_shell
{
	t_cmd		cmd_lst;
	int			last_exit_code;
	t_vars		vars;
}	t_shell;

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <unistd.h>

#endif