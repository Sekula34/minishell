/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 19:38:12 by fseles            #+#    #+#             */
/*   Updated: 2023/12/02 19:38:13 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishel.h"

//removes variables that matches key part of string
//removes from both env and ex list 
//return -1 if errro
//return 0 if ok
int	unset(char *string, t_vars **env_head, t_vars **ex_head)
{
	char *key;

	if(set_key(&key, string) == -1)
		return (-1);
	delete_element_with_key(key, ex_head);
	delete_element_with_key(key, env_head);
	free(key);
	return (0);
}
