/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shexit_exec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:50:29 by fseles            #+#    #+#             */
/*   Updated: 2024/01/16 15:32:25 by wvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishel.h"

static int	numeric_argument_check(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] == '+' || str[i] == '"' || str[i] == '-')
			i++;
		if (str[i] == '\0')
			break ;
		if (ft_isdigit(str[i]) != 1)
			return (0);
		i++;
	}
	return (1);
}

static char	*point_to_digit(char *string)
{
	char	*ptr;
	int		i;

	ptr = NULL;
	i = 0;
	while (string[i] != '\0')
	{
		if (string[i] == '-')
			return (NULL);
		if (ft_isdigit(string[i]) == 1)
		{
			ptr = string + i;
			return (ptr);
		}
		i++;
	}
	return (NULL);
}

static void	set_status(char *exit_argument, int *status)
{
	char	*digit;

	digit = point_to_digit(exit_argument);
	if (digit == NULL)
	{
		*status = 2;
		return ;
	}
	*status = ft_atoi(digit);
	return ;
}

int	shexit_exec(t_shell *shell, t_cmd *exit_cmd)
{
	int		argc;
	int		status;

	status = 0;
	//ft_printf("exit\n");
	argc = get_argc(exit_cmd->args);
	if (argc > 2)
	{
		ft_putstr_fd(" too many arguments\n", 2);
		shell->last_exit_code = export_exit_status(1, shell);
	}
	if (argc == 2)
	{
		if (numeric_argument_check(exit_cmd->args[1]) == 0)
		{
			ft_putstr_fd(" numeric argument required\n", 2);
			shell->last_exit_code = export_exit_status(2, shell);
		}
		set_status(exit_cmd->args[1], &status);
		export_exit_status(status, shell);
	}
	shexit(shell, shell->last_exit_code);
	return (0);
}
