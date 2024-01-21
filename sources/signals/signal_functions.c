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

void	interactive_sigint(int sig)
{
	// (void)sig;
	// g_signal = SIGINT;
	// write(2, "\n", 1);
	// rl_on_new_line();
	// rl_replace_line("", 0);
	// rl_redisplay();


	g_signal = sig;
	//write(1, "\n\n", 2);
	//ioctl(STDIN_FILENO, TIOCSTI, "\n");

	ft_printf("\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();


	// g_signal = sig;
	// //ft_printf("\n");
	// //puts("beforeioctl");
	// ft_printf("\n");
	// rl_replace_line("", 0);
	// rl_on_new_line();
	// rl_redisplay();
	//puts("wtf");
	//write(STDOUT_FILENO, "\n", 1);
	//ft_putchar_fd('\n', STDOUT_FILENO);
	//rl_on_new_line();
	// puts("here i am");
	// rl_redisplay();
	// puts("newline");
	//puts("hello\n");
}

void	heredoc_sigint(int sig)
{
	(void)sig;
	ioctl(STDIN_FILENO, TIOCSTI, "\n");
	g_signal = sig;
	rl_replace_line("", 0);
	rl_on_new_line();
}
