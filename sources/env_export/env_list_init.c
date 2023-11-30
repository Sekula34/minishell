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


//function that !!!!!allocates and connects all node of envp to linked list
//return 1 if succesfully done
//reuturn -1 if envp is NULL
//return -2 if error happens 
//if return -2 you should clear whole list
//function that clear this is called  clear_list_env
int env_list_init(t_vars **start, char **envp)
{
	int	i;
	t_vars *new_element; 
	
	i = 0;
	if (envp == NULL)
		return (-1);
	while (envp[i] != NULL)
	{
		new_element = create_element(envp[i]);
		if (new_element == NULL)
			return (-2);
		//create node
		add_element_back(start, new_element);
		i++;
	}
	return (1);	
}


int main(int argc, char **argv, char **envp)
{
	t_vars *head;
	t_vars *begin;
	head = NULL;
	env_list_init(&head, envp);
	begin = head;
	while(head != NULL)
	{
		printf("%s\t%s\n", head->key, head->value);
		head = head->next;
	}
	clear_list_env(&begin);
	return (0);
}
// int main()
// {
// 	t_vars *first, *second, *third;
// 	first = create_element("LANG=en");
// 	second = create_element("Hej=haj");
// 	third = create_element("DONKEY=Shrek");

// 	t_vars *head;
// 	head = NULL;
// 	t_vars *begin;


// 	add_element_back(&head, first);
// 	add_element_back(&head, second);
// 	add_element_back(&head, third);
// 	begin = head;
// 	while(head != NULL)
// 	{
// 		printf("%s, %s\n", head->key, head->value);
// 		head = head->next;
// 	}
// t_vars *to_delete;
// head = begin;
// while (head)
// {
// 	printf("Uso sam \n");
// 	to_delete = head;
// 	head = head->next;
// 	delete_element(&to_delete);
//}
// 	return (0);
// }