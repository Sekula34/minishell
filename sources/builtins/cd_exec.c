/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:04:15 by fseles            #+#    #+#             */
/*   Updated: 2023/12/13 17:04:17 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishel.h"

//count arguments in in char **
//if it is NULL reutunr 0;
//if it do not count NULL argument
static int get_argc(char **argv)
{
	int i;

	i = 0;
	if(argv == NULL)
		return (0);
	while(argv[i] != NULL)
	{
		i++;
	}
	return (i);
}

//call correct version of cd function
//return status of called function
//if arguments is bigger than 1 error;
int cd_exec(t_shell *shell, t_cmd *cd_cmd)
{
	int argc;
	argc = get_argc(cd_cmd->args);
	if(argc > 1)
	{
		ft_putstr_fd("cd with only relative or absoulute path page 6.\n", 2);
		return(EXIT_FAILURE);
	}
	else if (argc == 0)
		return(cd(NULL, &shell->head_ex, &shell->head_env));
	else
		return(cd(cd_cmd->args[0],&shell->head_ex, &shell->head_env));
	return(EXIT_FAILURE);
}
