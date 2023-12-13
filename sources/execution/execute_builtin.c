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
		cd(cmd->args[0], &(shell->head_ex), &(shell->head_env));
	if(builtin_num == 2)
		pwd(&(shell->head_ex), &(shell->head_env));
	if(builtin_num == 3)
		env((shell->head_env));
	if(builtin_num == 4)
		echo(cmd->args[0], 1);
	if(builtin_num == 5)
		exit(0);
	if(builtin_num == 6)
		unset(cmd->args[0], &(shell->head_ex), &(shell->head_env));
	if(builtin_num == 7)
		export(cmd->args[0], &(shell->head_ex), &(shell->head_env));
	return (0);
}