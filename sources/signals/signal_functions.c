/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 09:57:22 by fseles            #+#    #+#             */
/*   Updated: 2024/01/20 15:06:28 by wvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishel.h"

void	interactive_sigint(void)
{
	g_signal = 130;
	ft_printf("\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	heredoc_sigint(void)
{
	ioctl(STDIN_FILENO, TIOCSTI, "\n");
	g_signal = 130;
	rl_replace_line("", 0);
	rl_on_new_line();
}
