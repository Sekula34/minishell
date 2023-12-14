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

int pwd_exec(t_shell *shell, t_cmd *pwd_cmd)
{
	int argc;

	argc = get_argc(pwd_cmd->args);
	if(argc != 0)
	{
		ft_putstr_fd("pwd with no options page 6\n",2);
		return (2);
	}
	pwd(&shell->head_ex, &shell->head_env);
	return (0);
}