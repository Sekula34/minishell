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
// cd
// pwd 
// env 
// echo 
// exit 
// unset 
// export 
// if it is return 1, otherwise return 0
// return -1 if cmd is empty
int is_cmd_builtin(t_cmd *cmd)
{
	if(error_input(cmd) == 1)
		return (-1);
	if(ft_strncmp(cmd->cmd, "cd", 3) == 0)
		return (1);
	if(ft_strncmp(cmd->cmd, "pwd", 4) == 0)
		return (1);
	if(ft_strncmp(cmd->cmd, "env", 4) == 0)
		return (1);
	if(ft_strncmp(cmd->cmd, "echo", 5) == 0)
		return (1);
	if(ft_strncmp(cmd->cmd, "exit", 5) == 0)
		return (1);
	if(ft_strncmp(cmd->cmd, "unset", 6) == 0)
		return (1);
	if(ft_strncmp(cmd->cmd, "export", 7) == 0)
		return (1);
	return (0);
}
