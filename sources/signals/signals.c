/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 09:51:21 by fseles            #+#    #+#             */
/*   Updated: 2024/01/16 09:51:22 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishel.h"

static void	parent_exec(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

static void	child_exec(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}

static void	interactive_mode(void)
{
	signal(SIGINT, interactive_sigint);
	signal(SIGQUIT, SIG_IGN);
}

static void	heredoc_mod(void)
{
	signal(SIGINT, heredoc_sigint);
	signal(SIGQUIT, SIG_DFL);
}

//mode 1 interactive signals where ctrl + c 
//gives new readline and ctrl + \ is ignored
//mode 2 parent execution where ctrl + c and ctrl + \ are both ignored;
//mode 3 child_exec where both signal have default action
void	minishel_signals(int mode)
{
	if (mode == 1)
		interactive_mode();
	else if (mode == 2)
		parent_exec();
	else if (mode == 3)
		child_exec();
	else if (mode == 4)
		heredoc_mod();
	return ;
}
