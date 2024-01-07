/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:27:10 by fseles            #+#    #+#             */
/*   Updated: 2024/01/07 14:41:07 by wvan-der         ###   ########.fr       */
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
		if (head->value != NULL && head->key[0] != '?')
			printf("%s=%s\n", head->key, head->value);
		head = head->next;
	}
	return (0);
}
