#include "../../headers/minishel.h"

int execute_minishell(t_shell *shell)
{
	pid_t id;
	char **args;
	args= (char *[]){"~", NULL};

	printf("minishell path is :%s\n", shell->minishell_path);
	id = fork();
	if(id == -1)
	{
		perror("execute minishell fork failed");
		return (EXIT_FAILURE);
	}
	if(id == 0)
	{
		//child;
		execve("/home/fseles/42/minishell/minishell", args, shell->mini_env);
		perror("execute minishell");
		exit(EXIT_FAILURE);
	}
	//parent
	return(EXIT_SUCCESS);
}
