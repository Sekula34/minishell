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

//call function dependingon which redirect is encounterd
//in_fd, and out_fd are now standard input and output;
static int redirect_menu(t_redirect *red_list, int *in_fd, int *out_fd, int i)
{
	if(red_list->type == 'a')
		return(append_redirect(red_list, out_fd));
	if(red_list->type == 'h')
		return(heredoc_redirect(red_list,i, in_fd));
	if(red_list->type == 'i')
		return(input_redirect(red_list, in_fd));
	if(red_list->type == 'o')
		return(output_redirect(red_list, out_fd));
	return (1);
}

//call all redirection in list
//0 succesfull
//1 erorr;
int redirect_handler(t_redirect *red_list, int *in_fd, int *out_fd)
{
	int i = 0;
	if(red_list == NULL)
	{
		return (0);
	}
	while(red_list != NULL)
	{
		if(redirect_menu(red_list, in_fd, out_fd, i) != 0)
			return (1);
		red_list = red_list->next;
		i++;
	}
	return (0);
}
