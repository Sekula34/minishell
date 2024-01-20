/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:34:18 by fseles            #+#    #+#             */
/*   Updated: 2023/12/14 18:34:20 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishel.h"
#include "../../headers/data_types.h"

int	unset_exec(t_shell *shell, t_cmd *unset_cmd)
{
	int	argc;
	int	i;

	i = 1;
	argc = get_argc(unset_cmd->args);
	if (argc < 2)
		return (export_exit_status(0, shell));
	while (unset_cmd->args[i] != NULL)
	{
		unset(unset_cmd->args[i], &shell->head_env, &shell->head_ex);
		i++;
	}
	return (export_exit_status(0, shell));
}
