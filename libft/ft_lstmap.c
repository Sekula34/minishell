/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 10:55:49 by fseles            #+#    #+#             */
/*   Updated: 2023/09/14 10:55:53 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*pointer_head;
	t_list	*new_element;
	void	*sadrzaj;

	if (lst)
	{
		pointer_head = NULL;
		while (lst)
		{
			sadrzaj = (*f)(lst->content);
			new_element = ft_lstnew(sadrzaj);
			if (new_element == NULL)
			{
				ft_lstclear(&pointer_head, (*del));
				(*del)(sadrzaj);
				return (NULL);
			}
			ft_lstadd_back(&pointer_head, new_element);
			lst = lst->next;
		}
		return (pointer_head);
	}
	return (NULL);
}
