/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:41:38 by fseles            #+#    #+#             */
/*   Updated: 2023/12/14 15:41:40 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishel.h"

static int n_option(char *str)
{
	int i;
	int str_len;

	i = 1;
	if(str == NULL)
		return (0);
	str_len = ft_strlen(str);
	if(str[0] != '-' || str_len == 1)
		return(0);
	while(str[i] != '\0')
	{
		if(str[i] != 'n')
			return(0);
		i++;
	}
	return (1);
}

int echo_exec(t_cmd *echo_cmd, t_shell *shell)
{
	int argc;
	int is_option;
	int i;

	i = 1;
	argc = get_argc(echo_cmd->args);
	if(argc == 1)
	{
		echo(NULL);
		printf("\n");
	}
	is_option = n_option(echo_cmd->args[1]);
	if(is_option == 1)
		i++;
	while(echo_cmd->args[i] != NULL)
	{
		echo(echo_cmd->args[i]);
		if(echo_cmd->args[i + 1] != NULL)
			printf(" ");
		i++;
	}
	if(is_option == 0)
		printf("\n");
	return (export_exit_status(0, shell));
}
