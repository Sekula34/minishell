/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:53:13 by fseles            #+#    #+#             */
/*   Updated: 2023/12/13 14:53:15 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishel.h"

//return 1 if failed
//return 0 if success
//initialize both headex, and head_env
//sorts head_ex;
int shell_init(t_shell *shell, char **envp)
{
	shell->head_env = NULL;
	shell->head_ex = NULL;
	shell->minishell_path = NULL;
	shell->mini_env = NULL;
	if(env_list_init(&(shell->head_env), envp) != 1)
		return(EXIT_FAILURE);
	if(env_list_init(&(shell->head_ex), envp) != 1)
		return(EXIT_FAILURE);
	list_sort_alpha(shell->head_ex);
	shell->minishell_path = getcwd(shell->minishell_path, 0);
	if(shell->minishell_path == NULL)
	{
		perror("Path to minishell cannot be set\n");
		return (EXIT_FAILURE);
	}
	return(EXIT_SUCCESS);
}
