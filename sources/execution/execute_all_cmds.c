/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_all_cmds.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 20:13:01 by fseles            #+#    #+#             */
/*   Updated: 2024/01/05 16:32:26 by wvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishel.h"

int execute_all_cmds(t_shell *shell)
{
	(void)(*shell);
	int	cmd_count;
	minishel_signals(2);
	
	if (set_number_of_commands(&cmd_count, shell->cmd_lst) == EXIT_FAILURE)
		return(EXIT_FAILURE);
	if(cmd_count > 1)
	{
		if(execute_multiple_cmd(cmd_count, shell) != 0)
			return(EXIT_FAILURE);
		return(EXIT_SUCCESS);
	}
	if(one_command_exec(shell->cmd_lst, shell) != 0)
		return(EXIT_FAILURE);
	return(EXIT_SUCCESS);
}
