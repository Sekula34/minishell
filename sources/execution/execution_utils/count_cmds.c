/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 20:22:32 by fseles            #+#    #+#             */
/*   Updated: 2023/12/08 20:22:34 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../../headers/minishel.h"

//return number of commands in list of commands
//if input cmd is NULL return 0
int get_number_of_commands(t_cmd *cmd)
{
	int counter;

	counter = 0;
	if (cmd == NULL)
		return (0);
	while (cmd != NULL)
	{
		counter++;
		cmd = cmd->next;
	}
	return(counter);
}
