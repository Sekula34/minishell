/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_all_cmds.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 20:13:01 by fseles            #+#    #+#             */
/*   Updated: 2023/12/08 20:13:03 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishel.h"

int execute_all_cmds(t_shell shell)
{
	(void)(shell);
	int	cmd_count;
	int **pipe_arr;

	pipe_arr = NULL;
	if (set_number_of_commands(&cmd_count, shell.cmd_lst) == EXIT_FAILURE)
		return(EXIT_FAILURE);
	if(cmd_count > 1)
	{
		if(make_pipes(&pipe_arr, cmd_count - 1) == EXIT_FAILURE)
			return(EXIT_FAILURE);
	}
	return(EXIT_SUCCESS);
}
