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

//set minishell executable 
//joining current working directory and program name 
//return 0 if ok
// retunr 1 if fail (fail is critical)
static int set_minishell_exec(char **program)
{
	char *path;

	path = NULL;
	path = getcwd(path, 0);
	if(path == NULL)
	{
		perror("Cannot set current working directory for path\n");
		return (EXIT_FAILURE);
	}
	*program = ft_strjoin(path, "/minishell");
	if(*program == NULL)
	{
		perror("strjoin in set minishell exec failed\n");
		return(free(path), EXIT_FAILURE);
	}
	return(free(path), EXIT_SUCCESS);
}

//return 1 if failed
//return 0 if success
//initialize both headex, and head_env
//sorts head_ex;
int shell_init(t_shell *shell, char **envp)
{
	shell->head_env = NULL;
	shell->head_ex = NULL;
	shell->minishell_exec = NULL;
	shell->mini_env = NULL;
	shell->pipe_arr = NULL;
	if(env_list_init(&(shell->head_env), envp) != 1)
		return(EXIT_FAILURE);
	if(env_list_init(&(shell->head_ex), envp) != 1)
		return(EXIT_FAILURE);
	list_sort_alpha(shell->head_ex);
	if(set_minishell_exec(&(shell->minishell_exec)) != 0)
		return(EXIT_FAILURE);
	return(EXIT_SUCCESS);
}
