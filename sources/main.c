#include "../headers/minishel.h"



int main(int argc, char **argv, char **envp)
{
	t_shell shell;
	char *line;

	if(shell_init(&shell, envp) != 0)
	{
		shexit(&shell, 1);
	}
	int i = 0;
	while(1)
	{
		line = readline("minishell: ");
		rl_on_new_line();
		if (parsing(&shell, line) == 0)
		{
			//error handeling

			return (1);
		}
		puts("after parsing");
		puts("");
		shell.first_cmd_copy = shell.cmd_lst;
		if(heredoc_parent_prepare(shell.cmd_lst) != 0)
			shexit(&shell, 1);
		if(execute_all_cmds(&shell) != 0)
			shexit(&shell, 1);
		clear_all_commands(&shell.first_cmd_copy);
		shell.first_cmd_copy = NULL;
	}
	shexit(&shell, 0);
	return(EXIT_SUCCESS);
}
