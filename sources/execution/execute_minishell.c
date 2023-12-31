#include "../../headers/minishel.h"

//increase shlvl and strjoin in in shlvlv that you need to freee later
//1 fail
//0 ok
static int increase_lvl(char *current_lvl, char **shlvl)
{
	int new_lvl;
	char *lvl_part;

	new_lvl = ft_atoi(current_lvl) + 1;
	if(new_lvl < 1)
		new_lvl = 1;
	lvl_part = ft_itoa(new_lvl);
	if(lvl_part == NULL)
	{
		perror("ft_itoa in increase lvl failed\n");
		return(EXIT_FAILURE);
	}
	*shlvl = ft_strjoin("SHLVL=", lvl_part);
	if(*shlvl == NULL)
	{
		perror("ft_strjoin in increase lvlv failed\n");
		return(free(lvl_part),EXIT_FAILURE);
	}
	free(lvl_part);
	return(EXIT_SUCCESS);
}

//set shlvlvto be SHLVL=1
//or SHLVL=n + 1;
//n is current lvl;
//0 ok 
// 1 fail
static int set_new_shlv(t_shell *shell, char **shlvl)
{
	t_vars *element;
	
	element = get_element("SHLVL", shell->head_env);
	if(element == NULL || element->value == NULL)
	{
		*shlvl = ft_strdup("SHLVL=1");
		if(*shlvl == NULL)
		{
			perror("ft_strdup in set_new_shlvl failed\n");
			return (EXIT_FAILURE);
		}
		return(EXIT_SUCCESS);
	}
	if(increase_lvl(element->value, shlvl) != 0)
		return(EXIT_FAILURE);
	return(EXIT_SUCCESS);
}

// export new shlvl and make new mini evirnoment 
// 0 ok 
// 1 fail
int export_shlvl(t_shell *shell)
{
	char *shlvl;

	if(set_new_shlv(shell, &shlvl) != 0)
		return(EXIT_FAILURE);
	if (export(shlvl, &shell->head_ex, &shell->head_env, 1) != 0)
		return(free(shlvl),EXIT_FAILURE);
	if(set_mini_env(&shell->mini_env, shell->head_env) != 0)
		return(free(shlvl),EXIT_FAILURE);
	free(shlvl);
	return(EXIT_SUCCESS);
}

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
		if(export_shlvl(shell) != 0)
			exit(EXIT_FAILURE);
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
