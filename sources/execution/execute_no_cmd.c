/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_no_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:24:52 by fseles            #+#    #+#             */
/*   Updated: 2024/01/16 18:24:55 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishel.h"

int execute_no_cmd(t_shell *shell)
{
	shell->stdin_cpy;
	shell->stdout_cpy;
	int new_in;
	int new_ot;

	new_in = 0;
	new_ot = 0;
	if(shell->cmd_lst == NULL)
	{
		ft_putstr_fd("Command node is NULL\n", 2);
	}
	if(set_original_input_output(&shell->stdin_cpy, &shell->stdout_cpy) != 0)
		return(EXIT_FAILURE);
	if(redirect_handler(shell->cmd_lst->redirect_lst, &new_in, &new_ot) != 0)
	{
		export_exit_status(1, shell);
	}
	if(reset_fd(shell->stdin_cpy, shell->stdout_cpy, new_in, new_ot) != 0)
		return (EXIT_FAILURE);
	close(shell->stdin_cpy);
	close(shell->stdout_cpy);
	return(EXIT_SUCCESS);
}
