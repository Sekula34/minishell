/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:14:14 by fseles            #+#    #+#             */
/*   Updated: 2023/09/13 19:14:19 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*element;
	t_list	*element_to_delete;

	if (lst != NULL)
	{
		if (*lst)
		{
			element = *lst;
			while (element != NULL)
			{
				element_to_delete = element;
				element = element->next;
				ft_lstdelone(element_to_delete, (*del));
			}
			*lst = NULL;
		}
	}
}
