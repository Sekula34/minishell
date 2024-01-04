/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_one_command.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:00:22 by fseles            #+#    #+#             */
/*   Updated: 2023/12/11 12:00:24 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishel.h"
//execution without redirections
//0 if everythin ok 
//1 if something broken
static int exec_one(t_cmd *cmd, t_shell *shell, int original_stdin, int original_stdout)
{
	int builtin_cmd;
	int mini;

	builtin_cmd = is_cmd_builtin(cmd);
	if(builtin_cmd > 0)
	{
		execute_builtin(builtin_cmd, shell, cmd);
		return(0);
	}
	if(set_mini_env(&shell->mini_env, shell->head_env) == 1)
		return (EXIT_FAILURE);
	mini = is_minishell(cmd);
	if(mini == 1)
	{
		execute_minishell(shell);
		return(clear_mini_env(&shell->mini_env),EXIT_SUCCESS);
	}
	if(execute_original_cmd(shell, cmd, original_stdin, original_stdout) != 0)
		return (clear_mini_env(&shell->mini_env),EXIT_FAILURE);
	clear_mini_env(&shell->mini_env);
	return(EXIT_SUCCESS);
}
//in orstdin and or_stdout are copies of original fds 1 an 0
//1 if faile
//0 if ok
static int set_original_input_output(int *or_stdin, int *or_stdout)
{
	*or_stdin = dup(STDIN_FILENO);
	if(*or_stdin == -1)
	{
		perror("dup in one_command_exec failed\n");
		return (EXIT_FAILURE);
	}
	*or_stdout = dup(STDOUT_FILENO);
	if(*or_stdout == -1)
	{
		perror("second dup in one_command_exec failed\n");
		close(*or_stdin);
		return(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int reset_fd(int fd_in, int fd_out, int new_fd_in, int new_fd_out)
{
	if(new_fd_in != 0)
	{
		if(dup2(fd_in, STDIN_FILENO) == -1)
		{
			perror("dup2 in reset fd failed \n");
			close(new_fd_in);
			close(new_fd_out);
			return (EXIT_FAILURE);
		}
	}
	if(new_fd_out != 0)
	{
		if(dup2(fd_out, STDOUT_FILENO) == -1)
		{
			perror("second dup2 in reset fd failed\n");
			close(new_fd_in);
			close(new_fd_out);
			return(EXIT_FAILURE);
		}
	}
	close(new_fd_in);
	close(new_fd_out);
	return(EXIT_SUCCESS);
}

//complete execution of one command
//originalstdin and originalstdout containt stdin and stdout fd
//they are used to reset stdin and stoud to 0 an 1 after redirection redirect stdin and stoud 
//to some custom files
//this original stdin and stoud are open from seting until end of this function
//therfore in execution if execution is making childre they are inherited and they need to be close in child
int one_command_exec(t_cmd *cmd, t_shell *shell)
{
	int original_stdin;
	int original_stdout;
	int new_in;
	int new_ot;

	new_in = 0;
	new_ot = 0;
	if(set_original_input_output(&original_stdin, &original_stdout) != 0)
		return(EXIT_FAILURE);
	if(redirect_handler(cmd->redirect_lst, &new_in, &new_ot)!= 0)
		return(EXIT_FAILURE);
	if(exec_one(cmd, shell, original_stdin, original_stdout) != 0)
		return(EXIT_FAILURE);
	if(reset_fd(original_stdin, original_stdout, new_in, new_ot) != 0)
		return (EXIT_FAILURE);
	close(original_stdin);
	close(original_stdout);
	return(EXIT_SUCCESS);
}
