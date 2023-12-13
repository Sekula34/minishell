/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_simple_command.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:01:56 by fseles            #+#    #+#             */
/*   Updated: 2023/12/13 14:01:58 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishel.h"

int execute_simple_command(t_shell *shell)
{
	int is_builtin;

	is_builtin = is_cmd_builtin(shell->cmd_lst);
	if(is_builtin > 0)
	{
		//builting execute
	}
}