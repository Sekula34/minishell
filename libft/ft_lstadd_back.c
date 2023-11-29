/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:31:21 by fseles            #+#    #+#             */
/*   Updated: 2023/11/29 16:35:41 by wvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new_lst)
{
	t_list	*last_element;

	if (lst != NULL)
	{
		if (*lst != NULL)
		{
			last_element = ft_lstlast(*lst);
			last_element->next = new_lst;
		}
		else
		{
			*lst = new_lst;
		}
	}
}
