/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 09:51:21 by fseles            #+#    #+#             */
/*   Updated: 2024/01/19 16:34:31 by wvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishel.h"

static void parent_exec()
{
	//ft_printf("parent signals activated\n");
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

static void child_exec()
{
	//ft_printf("child signals activated \n");
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}

static void interactive_mode()
{
	//ft_printf("interactive signals acitaved\n");
	signal(SIGINT, interactive_sigint);
	signal(SIGQUIT, SIG_IGN);
}
//mode 1 interactive signals where ctrl + c gives new readline and ctrl + \ is ignored
//mode 2 parent execution where ctrl + c and ctrl + \ are both ignored;
//mode 3 child_exec where both signal have default action
void minishel_signals(int mode)
{
	if(mode == 1)
		interactive_mode();
	else if(mode == 2)
		parent_exec();
	else if(mode == 3)
		child_exec();
	else
		return ;
}
