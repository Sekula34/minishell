/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:42:45 by fseles            #+#    #+#             */
/*   Updated: 2023/12/01 11:42:46 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishel.h"

//switching elements in list. IF order was 1, 2, 3
//after this will be 2, 1, 3
//do nothing if there is not at least 2 elements
//switchin content of nodes not nodes itself
static void	switch_elements(t_vars *first_element)
{
	t_vars	*second_element;
	char	*temp_key;
	char	*temp_value;

	if (first_element == NULL)
		return ;
	second_element = first_element->next;
	if (second_element == NULL)
		return ;
	temp_key = first_element->key;
	temp_value = first_element->value;
	first_element->key = second_element->key;
	first_element->value = second_element->value;
	second_element->key = temp_key;
	second_element->value = temp_value;
}

//take one element and check if key of next element is smaller
//if next is smaller return 1, otherwise 0
//example ARG=, BASH= return 0
// BASH=, ARG return 1
static int	is_next_smaller(t_vars *element)
{
	t_vars	*second_element;
	char	*first_key;
	char	*second_key;
	int		key_len;
	int		result;

	if (element == NULL)
		return (0);
	second_element = element->next;
	if (second_element == NULL)
		return (0);
	first_key = element->key;
	second_key = second_element->key;
	key_len = ft_strlen(first_key);
	result = ft_strncmp(first_key, second_key, key_len);
	if (result < 0)
		return (-1);
	else if (result == 0)
		return (0);
	return (1);
}

//alphabetical sorting list to be used for 
//export command (same as env but in order)
void	list_sort_alpha(t_vars *head)
{
	t_vars	*i;
	t_vars	*j;

	if (head == NULL)
		return ;
	i = head;
	while (i->next != NULL)
	{
		j = head;
		while (j->next != NULL)
		{
			if (is_next_smaller(j) == 1)
			{
				switch_elements(j);
			}
			j = j->next;
		}
		i = i->next;
	}
}

// void list_sort_alpha_test(t_vars *head)
// {
// 	t_vars *i;
// 	t_vars *j;
// 	t_vars *begin;
// 	int is_smaller;

// 	begin = *head;
// 	i = *head;
// 	printf("list in function sorting is \n");
// 	env(*head);
// 	while(i)
// 	{
// 		j = i;
// 		while(j)
// 		{
// 			is_smaller = is_next_smaller(j);
// 			if(is_smaller== 1)
// 			{
// 				switch_elements(j);
// 				if(j->next == begin)
// 					begin = j;
// 				//continue;
// 			}
// 			j = j->next;
// 		}
// 		i = i->next;
// 	}
// 	*head = begin;
// }
// int main(int argc, char **argv, char **envp)
// {
// 	t_vars *head; 
// 	head = NULL;
// 	t_vars *first;
// 	t_vars *second; 
// 	t_vars *third;
// 	t_vars *fourth;
// 	// first = create_element("G=1");
// 	// second = create_element("A=2");
// 	// third = create_element("Z=3");
// 	// fourth = create_element("D=4");
// 	// add_element_back(&head, first);
// 	// add_element_back(&head, second);
// 	// add_element_back(&head, third);
// 	// add_element_back(&head, fourth);
// 	env_list_init(&head, envp);
// 	env(head);
// 	printf("\n");
// 	//switch_elements(&(head->next));
// 	list_sort_alpha(head);
// 	//switch_elements(head);
// 	printf("After killer function\n");
// 	env(head);
// 	//list_sort_alpha_test(&head);
// 	//env(head);
// 	clear_list_env(&head);
// 	return (0);
// }
