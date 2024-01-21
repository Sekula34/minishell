/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 18:38:17 by wvan-der          #+#    #+#             */
/*   Updated: 2024/01/21 19:42:27 by wvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishel.h"

void	check_g_signal(t_shell *shell)
{
	if (g_signal != 0)
	{
		if (export_exit_status(g_signal + 128, shell) != 0)
			shexit(shell, 1);
		g_signal = 0;
	}
}

void	setting_compare_var(char *line, char *eof, int *compare)
{
	if (line == NULL)
		*compare = 0;
	else
		*compare = ft_strncmp(line, eof, ft_strlen(eof) + 1);
}
