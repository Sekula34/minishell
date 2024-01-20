/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_original_cmd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 14:28:53 by fseles            #+#    #+#             */
/*   Updated: 2024/01/20 14:28:54 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishel.h"

static void	child_function(int original_stdin, int original_stdout,
	t_cmd *cmd, t_shell *shell)
{
	close(original_stdin);
	close(original_stdout);
	minishel_signals(3);
	child_executor(cmd, shell);
}

static int	parent_function_set_status(pid_t child_id, int *exit_code)
{
	int		status;
	pid_t	killed_child;

	*exit_code = 0;
	killed_child = waitpid(child_id, &status, 0);
	if (killed_child == -1)
	{
		perror("waitpid");
		*exit_code = 1;
		return (EXIT_FAILURE);
	}
	if (WIFEXITED(status))
	{
		*exit_code = WEXITSTATUS(status);
		return (EXIT_SUCCESS);
	}
	if (WIFSIGNALED(status))
	{
		*exit_code = WTERMSIG(status) + 128;
		ft_printf("\n");
		return (EXIT_SUCCESS);
	}
	return (1);
}

//execute original command
//failure only if something broke 
//otherwise success
int	execute_original_cmd(t_shell *shell, t_cmd *cmd,
	int original_stdin, int original_stdout)
{
	pid_t	id;
	int		exit_code;

	if (cmd == NULL)
		return (export_exit_status(127, shell));
	if (cmd->cmd == NULL)
		return (export_exit_status(127, shell));
	if (set_cmd_path(cmd, shell) != 0)
		return (export_exit_status(127, shell));
	if (cmd->path == NULL)
	{
		ft_putstr_fd("Command not found \n", 2);
		return (export_exit_status(127, shell));
	}
	id = fork();
	if (id == -1)
	{
		perror("fork in execute original cmd failed \n");
		return (EXIT_FAILURE);
	}
	if (id == 0)
		child_function(original_stdin, original_stdout, cmd, shell);
	parent_function_set_status(id, &exit_code);
	return (export_exit_status(exit_code, shell));
}
