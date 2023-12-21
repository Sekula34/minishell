

#include "../../headers/minishel.h"



int execute_original_cmd(t_shell *shell, t_cmd *cmd)
{
	pid_t id;

	if(cmd == NULL)
		return(EXIT_SUCCESS);
	if(cmd->cmd == NULL)
		return (EXIT_SUCCESS);
	//path_setter
	id = fork();
	if(id == -1)
	{
		perror("fork in execute original cmd failed \n");
		return(EXIT_FAILURE);
	}
	if(id == 0)
	{
		//child
	}
	//parent
}

