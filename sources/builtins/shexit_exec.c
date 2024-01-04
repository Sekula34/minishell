/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shexit_exec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:50:29 by fseles            #+#    #+#             */
/*   Updated: 2023/12/14 17:50:30 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishel.h"

static int numeric_argument_check(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if(ft_isdigit(str[i]) != 1)
			return (0);
		i++;
	}
	return (1);
}

int shexit_exec(t_shell *shell, t_cmd *exit_cmd)
{
	int argc;
	int status;

	status = 0;
	printf("exit\n");
	argc = get_argc(exit_cmd->args);
	if(argc > 1)
	{
		ft_putstr_fd("To many arguments\n", 2);
		return (export_exit_status(2, shell));
	}
	if(argc == 1)
	{
		if(numeric_argument_check(exit_cmd->args[0]) == 0)
		{
			ft_putstr_fd("Numeric argument required\n", 2);
			return(export_exit_status(2, shell));
		}
		status = atoi(exit_cmd->args[0]);
	}
	shexit(shell, status);
	return (0);
}
