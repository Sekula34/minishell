#include "../../../headers/minishel.h"

//execute command
//exit success cannot be returnd cuzz of execve
//close original_stdin and original_stdout
//those are copies of fd 0 and 1 and they are closed in parent later
//they need to be close inside child that is why they are here 
int child_executor(t_cmd *cmd, t_shell *shell)
{
	if(cmd == NULL)
	{
		ft_putstr_fd("there is no command to execute\n", 2);
		exit(EXIT_FAILURE);
	}
	if(cmd->path == NULL)
	{
		ft_putstr_fd("Command path not found\n", 2);
		exit(127);
	}
	execve(cmd->path, cmd->args, shell->mini_env);
	perror("child executor\n");
	exit(126);
}
