#include "../../../headers/minishel.h"

//check if command exist and if it executable
//if does not exist return 127
//if does exist but it is not executable return 126
int check_command_acces(char *cmd_path)
{
	int acc_val;

	acc_val = access(cmd_path, F_OK);
	if(acc_val != 0)
	{
		perror("minishell");
		return (127);
	}
	acc_val = access(cmd_path, X_OK);
	if(acc_val != 0)
	{
		perror("minishell error");
		return(126);
	}
	return (0);
	
}

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
		exit(127);
	}
	// if(cmd->path == NULL)
	// {
	// 	ft_putstr_fd("Command path not found\n", 2);
	// 	exit(127);
	// }
	shell->last_exit_code = check_command_acces(cmd->path);
	if(shell->last_exit_code != 0)
		exit(shell->last_exit_code);
	execve(cmd->path, cmd->args, shell->mini_env);
	perror("child executor\n");
	exit(126);
}
