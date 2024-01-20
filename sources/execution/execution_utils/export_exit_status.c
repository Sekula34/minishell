/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_exit_status.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 13:45:03 by fseles            #+#    #+#             */
/*   Updated: 2024/01/20 13:45:47 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishel.h"

//exporting exit status in t_vars to be accesible later with $?
//0 ok 
//1 failed
int	export_exit_status(int exit_number, t_shell *shell)
{
	char	*exit_chr;
	char	*full_string;

	exit_chr = ft_itoa(exit_number);
	shell->last_exit_code = 1;
	if (exit_chr == NULL)
	{
		perror("ft_itoa in export exit failed\n");
		return (EXIT_FAILURE);
	}
	full_string = ft_strjoin("?=", exit_chr);
	if (full_string == NULL)
	{
		perror("ft_strjoin in export exit status failed\n");
		return (free(exit_chr), EXIT_FAILURE);
	}
	if (export(full_string, &shell->head_ex, &shell->head_env, 0) != 0)
		return (free(exit_chr), free(full_string), EXIT_FAILURE);
	shell->last_exit_code = exit_number;
	return (free(exit_chr), free(full_string), EXIT_SUCCESS);
}
