/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 20:22:32 by fseles            #+#    #+#             */
/*   Updated: 2024/01/16 17:57:14 by wvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../../headers/minishel.h"

//return number of commands in list of commands
//if input cmd is NULL return 0
static int get_number_of_commands(t_cmd *cmd)
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

//does not allocate
//just set noc to be number of commands
//return 1 on failure (when number of commnads is 0 or cmd is NULL)
int set_number_of_commands(int *noc, t_cmd *cmd)
{
	*noc = get_number_of_commands(cmd);
	if (*noc == 0)
	{
		ft_putstr_fd("There is not even one command in list or list is empty\n", 2);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
