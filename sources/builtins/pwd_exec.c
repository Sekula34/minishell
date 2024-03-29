/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:44:54 by fseles            #+#    #+#             */
/*   Updated: 2023/12/14 13:44:55 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishel.h"

int	pwd_exec(t_shell *shell, t_cmd *pwd_cmd)
{
	int	argc;
	int	status;

	argc = get_argc(pwd_cmd->args);
	status = pwd(&shell->head_ex, &shell->head_env);
	if (status != 0)
		status = 2;
	return (export_exit_status(status, shell));
}
