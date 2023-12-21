#include "../../headers/minishel.h"

int execute_minishell(t_shell *shell)
{
	pid_t id;
	char **args;
	args= (char *[]){"minishell", NULL};

	id = fork();
	if(id == -1)
	{
		perror("execute minishell fork failed");
		return (EXIT_FAILURE);
	}
	if(id == 0)
	{
		//child;
		execve(shell->minishell_exec, args, shell->mini_env);
		perror("execute minishell");
		exit(EXIT_FAILURE);
	}
	//parent
	// pid_t terminated_pid;
	int status;
	
	// terminated_pid = wait(&status);
	wait(&status);
	// printf("Child process %d terminated with status %d\n", terminated_pid, WEXITSTATUS(status));
	return(EXIT_SUCCESS);
}
