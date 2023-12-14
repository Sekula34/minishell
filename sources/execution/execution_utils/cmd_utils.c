/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:47:32 by fseles            #+#    #+#             */
/*   Updated: 2023/12/14 13:47:33 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../../headers/minishel.h"
//count arguments in in char **
//if it is NULL reutunr 0;
//if it do not count NULL argument
int get_argc(char **argv)
{
	int i;

	i = 0;
	if(argv == NULL)
		return (0);
	while(argv[i] != NULL)
	{
		i++;
	}
	return (i);
}
