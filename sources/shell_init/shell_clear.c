/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 14:35:15 by fseles            #+#    #+#             */
/*   Updated: 2024/01/21 19:45:31 by wvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishel.h"

void	clear_one_redirect(t_redirect **redirect)
{
	if (redirect == NULL || *redirect == NULL)
		return ;
	if ((*redirect)->type == 'h')
	{
		here_doc_file_delete(*redirect);
	}
	free((*redirect)->file_name);
	(*redirect)->file_name = NULL;
	free(*redirect);
	(*redirect) = NULL;
}

void	clear_redirects(t_redirect **list)
{
	t_redirect	*to_delete;

	if (list == NULL || *list == NULL)
		return ;
	while (*list != NULL)
	{
		to_delete = (*list)->next;
		clear_one_redirect(list);
		*list = to_delete;
		to_delete = NULL;
	}
}

void	clear_one_command(t_cmd **cmd)
{
	if (cmd == NULL || *cmd == NULL)
		return ;
	clear_redirects(&(*cmd)->redirect_lst);
	free((*cmd)->path);
	free((*cmd)->cmd);
	free(*cmd);
}

void	clear_all_commands(t_cmd **cmd_list)
{
	t_cmd	*to_delete;

	if (cmd_list == NULL || *cmd_list == NULL)
		return ;
	while (*cmd_list != NULL)
	{
		to_delete = (*cmd_list)->next;
		delete_cmd_element(cmd_list);
		*cmd_list = to_delete;
		to_delete = NULL;
	}
}

void	shell_clear(t_shell *shell)
{
	clear_list_env(&shell->head_env);
	clear_list_env(&shell->head_ex);
	clear_pipe_array(&shell->pipe_arr);
	clear_mini_env(&shell->mini_env);
	free(shell->minishell_exec);
	clear_all_commands(&shell->first_cmd_copy);
}
