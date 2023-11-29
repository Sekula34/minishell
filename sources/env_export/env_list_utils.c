/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:52:38 by fseles            #+#    #+#             */
/*   Updated: 2023/11/29 15:52:40 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishel.h"

//!!!allocates space for element
//string that this elements containt are also allocated and 
//needs to be free after
//element contains key, and value
//str is for example HOME=/nfs/homes/fseles
//key in this case is HOME=
//value is /nfs/homes/fseles
//if key or value is NULL do not create element
//element next is set to NULL here
t_vars *create_element(char *str)
{
	char	*key;
	char	*value;
	t_vars	*new_element;

	key = get_key(str);
	if (key == NULL)
		return (NULL);
	value = get_value(str);
	if (value == NULL)
		return (free(key), NULL);
	new_element = malloc(sizeof(t_vars));
	if(new_element == NULL)
	{
		free(key);
		free(value);
		perror("allocation of t_vars elemetns failed\n");
		return (NULL);
	}
	new_element->key = key;
	new_element->value = value;
	new_element->next = NULL;
	return (new_element);
}

//deltes element and his 2 allocated chars
//for key and value
void delete_element(t_vars **element_to_delete)
{
	t_vars *delete;

	delete = *element_to_delete;
	free(delete->key);
	free(delete->value);
	free(delete);
}

//add element at the end of list
//if head is null do nothing
//if head points to NUll that meand new_element is first now
void add_element_back(t_vars **head, t_vars *new_element)
{
	t_vars *last_element;

	if (head == NULL)
		return ;
	if (*head == NULL)
	{
		*head = new_element;
		return ;
	}
	last_element = *head;
	while(last_element->next != NULL)
	{
		last_element = last_element->next;
	}
	last_element->next = new_element;
}
