#include "../headers/minishel.h"



int main(int argc, char **argv, char **envp)
{
	t_shell shell;
	char *line;
	int	parsing_return;

	parsing_return = 0;


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
		if (line[0] == 0)
		{
			free(line);
			continue;
		}
		add_history(line);
		parsing_return = parsing(&shell, line);
		if (parsing_return == 0)
			shexit(&shell, 1);
		if (parsing_return == 2)
		{
			free(line);
			continue;
		}
		shell.first_cmd_copy = shell.cmd_lst;
 		if(heredoc_parent_prepare(shell.cmd_lst) != 0)
			shexit(&shell, 1);
		if(execute_all_cmds(&shell) != 0)
			shexit(&shell, 1);
		clear_all_commands(&shell.first_cmd_copy);
		shell.first_cmd_copy = NULL;
		i++;
		free(line);
		line = NULL;
	}
	shexit(&shell, 0);
	return(EXIT_SUCCESS);
}
