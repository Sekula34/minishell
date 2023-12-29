/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_exec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:57:27 by fseles            #+#    #+#             */
/*   Updated: 2023/12/14 18:57:29 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../headers/minishel.h"

int export_exec(t_shell *shell, t_cmd *export_cmd)
{
	int argc;
	int i;

	i = 0;
	argc = get_argc(export_cmd->args);
	if(argc == 0)
	{
		export(export_cmd->args[1], &shell->head_ex, &shell->head_env, 1);
		return 0;
	}
	while(export_cmd->args[i] != NULL)
	{
		export(export_cmd->args[i], &shell->head_ex, &shell->head_env, 1);
		i++;
	}
	return (0);
}
