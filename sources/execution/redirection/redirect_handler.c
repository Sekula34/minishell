/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:24:57 by fseles            #+#    #+#             */
/*   Updated: 2023/12/11 15:24:59 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../../headers/minishel.h"

static int redirect_menu(t_redirect *red_list)
{
	return (0);
}

int redirect_handler(t_redirect *red_list)
{
	if(red_list == NULL)
		return (0);
	while(red_list != NULL)
	{
		
		red_list = red_list->next;
	}
	return (0);
}
