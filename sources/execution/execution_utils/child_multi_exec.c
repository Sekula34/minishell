#include "../../../headers/minishel.h"


int execute_original_cmd_no_fork(t_shell *shell, t_cmd *cmd)
{
	

	if(cmd == NULL)
		return(EXIT_SUCCESS);
	if(cmd->cmd == NULL)
		return (EXIT_SUCCESS);
	if(set_cmd_path(cmd, shell) != 0)
		return (EXIT_FAILURE);
	child_executor(cmd, shell);
	return(EXIT_FAILURE);
}


static int execute_minishell_no_fork(t_shell *shell)
{
	char **args;
	args= (char *[]){"minishell", NULL};
	execve(shell->minishell_exec, args, shell->mini_env);
	perror("execute minishell");
	exit(EXIT_FAILURE);
}

//execution without redirections
//0 if everythin ok 
//1 if something broken
static int exec_one_b(t_cmd *cmd, t_shell *shell)
{
	int builtin_cmd;
	int mini;
	int builtin_exit;

	builtin_cmd = is_cmd_builtin(cmd);
	if(builtin_cmd > 0)
	{
		builtin_exit = execute_builtin(builtin_cmd, shell, cmd);
		shexit(shell, builtin_exit);
	}
	if(set_mini_env(&shell->mini_env, shell->head_env) == 1)
		exit (EXIT_FAILURE);
	mini = is_minishell(cmd);
	if(mini == 1)
	{
		execute_minishell_no_fork(shell);
		exit(EXIT_FAILURE);
	}
	if(execute_original_cmd_no_fork(shell, cmd) != 0)
		exit (EXIT_FAILURE);
	exit(EXIT_FAILURE);
}



//input file is pipe od reading end excpet if input file is 0 that is for first command
//output file is pipe on writing end except if output file is 0 that is for last command 
//0 ok 
//1 fail
int child_multi_exec(t_cmd *cmd, t_shell *shell, int input_file, int output_file)
{
	if(prepare_fds(cmd, shell, input_file, output_file) != 0)
		return(EXIT_FAILURE);
	if(set_mini_env(&shell->mini_env, shell->head_env) == 1)
		return (EXIT_FAILURE);
	exec_one_b(cmd, shell);
	return(EXIT_FAILURE);
}
