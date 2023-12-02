/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 18:01:16 by fseles            #+#    #+#             */
/*   Updated: 2023/12/02 18:01:18 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishel.h"

//return element based on key you are looking for
//return element or NULL if key does not exist in list
//return NULL if key is NULL
t_vars *get_element(char *key, t_vars *head)
{
	char *current_key;

	if(head == NULL || key == NULL)
		return (NULL);
	while (head)
	{
		current_key = head->key;
		if(ft_strncmp(current_key, key, ft_strlen(key)) == 0)
			return (head);
		head = head->next;
	}
	return (NULL);
}

