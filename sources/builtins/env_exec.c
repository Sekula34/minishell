/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:19:59 by fseles            #+#    #+#             */
/*   Updated: 2023/12/14 14:20:02 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishel.h"

int env_exec(t_shell *shell, t_cmd *env_cmd)
{
	int argc;

	argc = get_argc(env_cmd->args);
	// if(argc != 1)
	// {
	// 	ft_putstr_fd("env with no options or arguments\n", 2);
	// 	return (export_exit_status(2, shell));
	// }
	env(shell->head_env);
	return(export_exit_status(0, shell));
}
