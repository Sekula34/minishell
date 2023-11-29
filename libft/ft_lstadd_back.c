/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:31:21 by fseles            #+#    #+#             */
/*   Updated: 2023/09/13 18:31:23 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_element;

	if (lst != NULL)
	{
		if (*lst != NULL)
		{
			last_element = ft_lstlast(*lst);
			last_element->next = new;
		}
		else
		{
			*lst = new;
		}
	}
}
