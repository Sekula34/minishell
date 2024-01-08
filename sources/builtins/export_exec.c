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
	int status;

	i = 1;
	argc = get_argc(export_cmd->args);
	if(argc == 1)
	{
		status = export(export_cmd->args[1], &shell->head_ex, &shell->head_env, 1);
		if(status != 0)
			status = 2;
		return (export_exit_status(status, shell));
	}
	while(export_cmd->args[i] != NULL)
	{
		status = export(export_cmd->args[i], &shell->head_ex, &shell->head_env, 1);
		i++;
	}
	if(status != 0)
		status = 1;
	return (export_exit_status(status, shell));
}
