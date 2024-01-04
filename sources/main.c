#include "../headers/minishel.h"

int main(int argc, char **argv, char **envp)
{
	t_shell shell;
	if(shell_init(&shell, envp) != 0)
	{
		shexit(&shell, 1);
	}
	while(1)
	{
		//readline
		if (parsing(&shell, envp) == 0)
		{
			//error handeling
		}
		shell.first_cmd_copy = shell.cmd_lst;
		if(heredoc_parent_prepare(&shell.cmd_lst) != 0)
			shexit(&shell, 1);
		if(execute_all_cmds(&shell) != 0)
			shexit(&shell, 1);
		clear_all_commands(&shell.first_cmd_copy);
		shell.first_cmd_copy = NULL;
	}
	shexit(&shell, 0);
	return(EXIT_SUCCESS);
}
