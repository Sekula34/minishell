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
		if (!line)
			exit(0);
		/* line = "echo hello"; */
		if (parsing(&shell, line) == 0)
		{
			shexit(&shell, 1);
		}


		
		
		puts("after parsing");
		shell.first_cmd_copy = shell.cmd_lst;
 		if(heredoc_parent_prepare(shell.cmd_lst) != 0)
			shexit(&shell, 1);
		if(execute_all_cmds(&shell) != 0)
			shexit(&shell, 1);
		clear_all_commands(&shell.first_cmd_copy);
		shell.first_cmd_copy = NULL;
		i++;
	}
	shexit(&shell, 0);
	return(EXIT_SUCCESS);
}
