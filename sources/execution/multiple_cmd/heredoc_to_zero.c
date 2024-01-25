/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_to_zero.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 10:32:23 by fseles            #+#    #+#             */
/*   Updated: 2024/01/24 10:32:24 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishel.h"

static void	every_redirect_function(t_redirect *current_redirect)
{
	if (current_redirect == NULL)
		return ;
	current_redirect->to_delete = 0;
}

static void	every_cmd_function(t_cmd *current_cmd)
{
	t_redirect	*current_redirect;

	if (current_cmd == NULL)
		return ;
	if (current_cmd->redirect_lst == NULL)
		return ;
	current_redirect = current_cmd->redirect_lst;
	while (current_redirect != NULL)
	{
		every_redirect_function(current_redirect);
		current_redirect = current_redirect->next;
	}
	return ;
}

void	heredoc_to_zero(t_shell *shell)
{
	t_cmd	*current_cmd;

	if (shell == NULL)
		return ;
	current_cmd = shell->cmd_lst;
	while (current_cmd != NULL)
	{
		every_cmd_function(current_cmd);
		current_cmd = current_cmd->next;
	}
	return ;
}
