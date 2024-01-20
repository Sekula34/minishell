/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:39:05 by fseles            #+#    #+#             */
/*   Updated: 2024/01/16 15:22:04 by wvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishel.h"

//prints string on standard output 
//if n_option is 1 print without newline 
//otherwise prints newline
//return 0 
int	echo(char *string)
{
	if (string == NULL)
	{
	}
	else
	{
		ft_printf("%s", string);
	}
	return (0);
}
