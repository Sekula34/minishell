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


//call correct version of cd function
//return status of export_exit_status
//setting exit stauts in list
//if return different than 0 it is critical failure
int cd_exec(t_shell *shell, t_cmd *cd_cmd)
{
	int argc;
	int exit_status;

	argc = get_argc(cd_cmd->args);
	if(argc > 1)
	{
		ft_putstr_fd("cd with only relative or absoulute path page 6.\n", 2);
		return(export_exit_status(2, shell));
	}
	else if (argc == 0)
	{
		exit_status = cd(NULL, &shell->head_ex, &shell->head_env);
		if(exit_status != 0)
			exit_status = 2;
		return(export_exit_status(exit_status, shell));
	}
	else
	{
		exit_status = cd(cd_cmd->args[0],&shell->head_ex, &shell->head_env);
		if(exit_status != 0)
			exit_status = 2;
		return(export_exit_status(exit_status, shell));
	}
	return(export_exit_status(0, shell));
}
