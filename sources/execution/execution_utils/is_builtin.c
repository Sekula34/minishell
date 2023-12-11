/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:10:14 by fseles            #+#    #+#             */
/*   Updated: 2023/12/11 12:10:16 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include"../../../headers/minishel.h"

//return 1 if you find error
//return 0 if there is no error
//error is if cmd is empty or if cmd.cmd is NULL
static int error_input(t_cmd *cmd)
{
	if(cmd == NULL)
	{
		ft_putstr_fd("No command struct provided\n", 2);
		return (1);
	}
	if(cmd->cmd == NULL)
	{
		ft_putstr_fd("Command is NULL\n", 2);
		return (1);
	}
	return (0);
}


// function that checks if command is one of following:
// cd 1
// pwd 2
// env 3
// echo 4
// exit 5
// unset 6
// export 7
// if it is return 1 or bigger depend which is, otherwise return 0
// return -1 if cmd is empty and print message what happend
int is_cmd_builtin(t_cmd *cmd)
{
	if(error_input(cmd) == 1)
		return (-1);
	if(ft_strncmp(cmd->cmd, "cd", 3) == 0)
		return (1);
	if(ft_strncmp(cmd->cmd, "pwd", 4) == 0)
		return (2);
	if(ft_strncmp(cmd->cmd, "env", 4) == 0)
		return (3);
	if(ft_strncmp(cmd->cmd, "echo", 5) == 0)
		return (4);
	if(ft_strncmp(cmd->cmd, "exit", 5) == 0)
		return (5);
	if(ft_strncmp(cmd->cmd, "unset", 6) == 0)
		return (6);
	if(ft_strncmp(cmd->cmd, "export", 7) == 0)
		return (7);
	return (0);
}
