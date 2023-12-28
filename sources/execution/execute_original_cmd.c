

#include "../../headers/minishel.h"


//execute original command
//failure only if something broke 
//otherwise success
int execute_original_cmd(t_shell *shell, t_cmd *cmd, int original_stdin, int original_stdout)
{
	pid_t id;
	int status;

	if(cmd == NULL)
		return(EXIT_SUCCESS);
	if(cmd->cmd == NULL)
		return (EXIT_SUCCESS);
	if(set_cmd_path(cmd, shell) != 0)
		return (EXIT_FAILURE);
	id = fork();
	if(id == -1)
	{
		perror("fork in execute original cmd failed \n");
		return(EXIT_FAILURE);
	}
	if(id == 0)
	{
		close(original_stdin);
		close(original_stdout);
		child_executor(cmd, shell);
	}
	wait(&status);
	return(EXIT_SUCCESS);
}

