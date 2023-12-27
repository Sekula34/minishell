#include "../../../headers/minishel.h"


int execute_original_cmd_no_fork(t_shell *shell, t_cmd *cmd, int original_stdin, int original_stdout)
{
	

	if(cmd == NULL)
		return(EXIT_SUCCESS);
	if(cmd->cmd == NULL)
		return (EXIT_SUCCESS);
	if(set_cmd_path(cmd, shell) != 0)
		return (EXIT_FAILURE);
	child_executor(cmd, shell, original_stdin, original_stdout);
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
static int exec_one_b(t_cmd *cmd, t_shell *shell, int original_stdin, int original_stdout)
{
	int builtin_cmd;
	int mini;

	builtin_cmd = is_cmd_builtin(cmd);
	if(builtin_cmd > 0)
	{
		execute_builtin(builtin_cmd, shell, cmd);
		exit(0);
	}
	if(set_mini_env(&shell->mini_env, shell->head_env) == 1)
		exit (EXIT_FAILURE);
	mini = is_minishell(cmd);
	if(mini == 1)
	{
		execute_minishell_no_fork(shell);
		exit(EXIT_FAILURE);
	}
	if(execute_original_cmd_no_fork(shell, cmd, original_stdin, original_stdout) != 0)
		exit (EXIT_FAILURE);
	exit(EXIT_FAILURE);
}

int child_multi_exec(t_cmd *cmd, t_shell *shell, int input_pipe, int output_pipe)
{
	int new_in;
	int new_out;

	new_in = -1;
	new_out = -1;
	if(redirect_handler(cmd->redirect_lst, &new_in, &new_out) != 0)
		return (EXIT_FAILURE);
	if(set_input_output_file(&new_in, &new_out, &input_pipe, &output_pipe) != 0)
		return(EXIT_FAILURE);
	close_all_pipes(shell->pipe_arr);
	//perror("child close all pipes\n");
	// close(input_pipe);
	// close(output_pipe);
	// close(new_in);
	// close(new_out);
	if(set_mini_env(&shell->mini_env, shell->head_env) == 1)
		return (EXIT_FAILURE);
	exec_one_b(cmd, shell, new_in, new_out);
	return(EXIT_FAILURE);
}
