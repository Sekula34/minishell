/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:27:10 by fseles            #+#    #+#             */
/*   Updated: 2023/11/30 15:27:12 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishel.h"

//function that just prints everything in t_vars head from begging
//reproducing behaviour of env in bash 
//prints everything on standard output
//return (0) on success
//return (-1) if there is nothing in list
//list should be initialized before calling this (env_list_init)
int	env(t_vars *head)
{
	if (head == NULL)
		return (-1);
	while (head != NULL)
	{
		if(pos_of_equal(head->key) != -1)
		{
			if(head->value != NULL)
				printf("%s%s\n", head->key, head->value);
			else
				printf("%s\n", head->key);
		}
		head = head->next;
	}
	return (0);
}
