/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:50:46 by fseles            #+#    #+#             */
/*   Updated: 2023/09/13 15:50:51 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*novi_pointer;

	novi_pointer = malloc(sizeof(t_list));
	if (novi_pointer == NULL)
		return (NULL);
	novi_pointer->content = content;
	novi_pointer->next = NULL;
	return (novi_pointer);
}
