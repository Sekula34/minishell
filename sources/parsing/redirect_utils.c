/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:09:54 by wvan-der          #+#    #+#             */
/*   Updated: 2024/01/19 15:30:59 by wvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishel.h"

t_redirect	*make_redirect_node(char type, char *file_name)
{
	t_redirect	*new_node;

	new_node = malloc(sizeof(t_redirect));
	if (!new_node)
		return (NULL);
	new_node->type = type;
	new_node->file_name = file_name;
	new_node->del_flag = 0;
	new_node->next = NULL;
	return (new_node);
}

void	add_redirect_node(t_redirect **lst, t_redirect *new_lst)
{
	t_redirect	*last_element;

	if (lst != NULL)
	{
		if (*lst != NULL)
		{
			last_element = *lst;
			while (last_element->next)
				last_element = last_element->next;
			last_element->next = new_lst;
		}
		else
		{
			*lst = new_lst;
		}
	}
}
