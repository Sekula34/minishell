/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 13:21:36 by fseles            #+#    #+#             */
/*   Updated: 2024/01/20 13:21:41 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishel.h"

//set cmd-Path to correct executable if found
//return 1 if something failes 
//even if path is not found 0 will 
//be return but cmd_path will stay NULL(unchaged)
static int	try_one_path(char *path, t_cmd *cmd)
{
	char	*full_path;
	char	*plain_cmd;

	plain_cmd = ft_strjoin("/", cmd->cmd);
	if (plain_cmd == NULL)
	{
		perror("strjoin in try_one_path failed \n");
		return (EXIT_FAILURE);
	}
	full_path = ft_strjoin(path, plain_cmd);
	if (full_path == NULL)
	{
		perror("strjoin 2 in_try_one_path failed \n");
		return (free(plain_cmd), EXIT_FAILURE);
	}
	free(plain_cmd);
	if (access(full_path, F_OK) == 0)
	{
		cmd->path = full_path;
		return (EXIT_SUCCESS);
	}
	free(full_path);
	return (EXIT_SUCCESS);
}

//if correct path is found cmd->path is set and  different than NULL 
//if somethinf fails cmd->pat stays NULL but 1 will be returned
//return 0 if everythin ok
static int	find_correct_path(char *all_paths, t_cmd *cmd)
{
	char	**single_path;
	int		i;

	i = 0;
	cmd->path = NULL;
	single_path = ft_split(all_paths, ':');
	if (single_path == NULL)
	{
		perror("split in find_correct_path failed \n");
		return (EXIT_FAILURE);
	}
	while (single_path[i] != NULL)
	{
		if (try_one_path(single_path[i], cmd) == 1)
		{
			clear_mini_env(&single_path);
			return (EXIT_FAILURE);
		}
		if (cmd->path != NULL)
			break ;
		i++;
	}
	clear_mini_env(&single_path);
	return (EXIT_SUCCESS);
}

//set command path
//if path is unset cmd.path will be NULL and succes is return
//failure is return only if something failed
static int	path_finder(t_cmd *cmd, t_shell *shell)
{
	t_vars	*path_element;

	path_element = get_element("PATH", shell->head_env);
	if (path_element == NULL)
	{
		cmd->path = NULL;
		return (EXIT_SUCCESS);
	}
	if (path_element->value == NULL)
	{
		cmd->path = NULL;
		return (EXIT_SUCCESS);
	}
	if (find_correct_path(path_element->value, cmd) != 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	set_path_to_current_dir(t_shell *shell, char **path, char *file)
{
	t_vars	*current_dir;

	current_dir = get_element("PWD", shell->head_env);
	if (current_dir == NULL || current_dir->value == NULL)
	{
		ft_putstr_fd("PWD is unset so path to file cannot be found\n", 2);
		return (EXIT_SUCCESS);
	}
	*path = ft_strjoin(current_dir->value, file + 1);
	if (*path == NULL)
	{
		perror("ft_strjoin in set_path_to_current dir failed");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

//set command paths 
//cmd path will be either NULL or different than NULL
//if cmd path is NULL and 0 retutrend that means there is no such command
//if cmd pat is NULL and 1 is return something broke (CRITICAL failure)
//cmd path is different than NULL only if everything is ok
int	set_cmd_path(t_cmd *cmd, t_shell *shell)
{
	t_vars	*current_dir;

	cmd->path = NULL;
	if (cmd->cmd[0] == '/')
	{
		cmd->path = ft_strdup(cmd->cmd);
		if (cmd->path == NULL)
		{
			perror("strdup in set_cmd_path failed \n");
			return (EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
	if (cmd->cmd[0] == '.')
	{
		if (set_path_to_current_dir(shell, &cmd->path, cmd->cmd) != 0)
			return (EXIT_FAILURE);
		return (EXIT_SUCCESS);
	}
	if (path_finder(cmd, shell) != 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
