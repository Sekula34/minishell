/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 09:57:22 by fseles            #+#    #+#             */
/*   Updated: 2024/01/16 09:57:24 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishel.h"

void interactive_sigint()
{
	global_signal = 130;
	ft_printf("\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void heredoc_sigint()
{
	ft_printf("heredoc ctrl + c\n");
	global_signal = 130;
}
