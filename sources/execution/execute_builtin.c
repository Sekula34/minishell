/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:53:54 by fseles            #+#    #+#             */
/*   Updated: 2023/12/11 14:53:55 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishel.h"

// cd 1
// pwd 2
// env 3
// echo 4
// exit 5
// unset 6
// export 7
int execute_builtin(int builtin_num, t_shell *shell, t_cmd *cmd)
{
	if(builtin_num == 1)
		return(cd_exec(shell, cmd));
	if(builtin_num == 2)
		return(pwd_exec(shell, cmd));
	if(builtin_num == 3)
		return(env_exec(shell, cmd));
	if(builtin_num == 4)
		return(echo_exec(cmd));
	if(builtin_num == 5)
		return(shexit_exec(shell, cmd));
	if(builtin_num == 6)
		unset(cmd->args[0], &(shell->head_ex), &(shell->head_env));
	if(builtin_num == 7)
		export(cmd->args[0], &(shell->head_ex), &(shell->head_env));
	return (0);
}