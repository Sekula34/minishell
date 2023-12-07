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

//!!alllocates new element for linked list
//create elemnent that contains key and value
//Both key and value can be NULL (but better check if key exist)
//Return NULL if allocation fails
//return pointer of new element if everything is ok
t_vars	*create_element(char *key, char *value)
{
	t_vars	*new_element;

	new_element = malloc(sizeof(t_vars));
	if (new_element == NULL)
	{
		perror("Allocation of new element in create element fails\n");
		return (NULL);
	}
	new_element->key = key;
	new_element->value = value;
	new_element->next = NULL;
	return (new_element);
}

//deltes element and his 2 allocated chars
//for key and value
void	delete_element(t_vars **element_to_delete)
{
	t_vars	*delete;

	delete = *element_to_delete;
	free(delete->key);
	free(delete->value);
	free(delete);
}

//clear whole list from head till end of list
void	clear_list_env(t_vars **head)
{
	t_vars	*to_delete;

	while (*head != NULL)
	{
		to_delete = *head;
		*head = (*head)->next;
		delete_element(&to_delete);
	}
}

//add element at the end of list
//if head is null do nothing
//if head points to NUll that meand new_element is first now
void	add_element_back(t_vars **head, t_vars *new_element)
{
	t_vars	*last_element;

	if (head == NULL)
		return ;
	if (*head == NULL)
	{
		*head = new_element;
		return ;
	}
	last_element = *head;
	while (last_element->next != NULL)
	{
		last_element = last_element->next;
	}
	last_element->next = new_element;
}

//goes through list and counts how many elemetns are there
//return number of elements or 0 if list does not exist
int	count_list_elements(t_vars *head)
{
	int	i;

	i = 0;
	if (head == NULL)
		return (0);
	while (head != NULL)
	{
		i++;
		head = head->next;
	}
	return (i);
}
