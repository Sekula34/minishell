/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:47:07 by fseles            #+#    #+#             */
/*   Updated: 2023/11/29 13:47:09 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishel.h"


//function that allocates and connects all node of envp to linked list
//return 1 if succesfully done
//reuturn -1 if envp is NULL
//return -2 if error happens
int env_list_init(t_vars **start, char **envp)
{
	int	i;

	i = 0;
	if (envp == NULL)
		return (-1);
	while (envp[i] != NULL)
	{
		//create node
		//connect node
		i++;
	}
	return (1);
	
}

int main()
{
	t_vars *first, *second, *third;
	first = create_element("LANG=en");
	second = create_element("Hej=haj");
	third = create_element("DONKEY=Shrek");

	t_vars *head;
	head = NULL;
	t_vars *begin;


	add_element_back(&head, first);
	add_element_back(&head, second);
	add_element_back(&head, third);
	begin = head;
	while(head != NULL)
	{
		printf("%s, %s\n", head->key, head->value);
		head = head->next;
	}
	t_vars *to_delete;
	head = begin;
	while (head)
	{
		printf("Uso sam \n");
		to_delete = head;
		head = head->next;
		delete_element(&to_delete);
	}
	return (0);
}