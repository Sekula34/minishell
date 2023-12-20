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

int one_command_exec(t_cmd *cmd, t_shell *shell)
{
	int builtin_cmd;
	int mini;

	builtin_cmd = is_cmd_builtin(cmd);
	if(builtin_cmd > 0)
	{
		execute_builtin(builtin_cmd, shell, cmd);
		return(0);
	}
	mini = is_minishell(cmd);
	if(mini == 1)
	{
		
	}
	return(1);
}
