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
	char *in_key_plain;

	if(head == NULL || key == NULL)
		return (NULL);
	in_key_plain = get_plain_key(key);
	if (in_key_plain == NULL)
		return (NULL);
	while (head)
	{
		current_key = head->key;
		if(ft_strncmp(current_key, in_key_plain, ft_strlen(in_key_plain)) == 0)
		{
			free(in_key_plain);
			return (head);
		}
		head = head->next;
	}
	free(in_key_plain);
	return (NULL);
}

//delete element from list mathing the key
//list stays connected
void delete_element_with_key(char *key, t_vars **head)
{
	t_vars *to_delete;
	t_vars *element;

	if(key == NULL || *head == NULL)
		return ;
	element = *head;
	to_delete = get_element(key, *head);
	if(to_delete == NULL)
		return ;
	if(element == to_delete)
		*head = to_delete->next;
	else
	{
		while(element->next)
		{
			if(element->next == to_delete)
			{
				element->next = to_delete->next;
				break;
			}
			element = element->next;
		}
	}
	delete_element(&to_delete);
}

