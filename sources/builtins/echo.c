/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willem <willem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:39:05 by fseles            #+#    #+#             */
/*   Updated: 2024/01/08 17:30:27 by willem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishel.h"

static void echo_print(char *string)
{
	int i;

	i = 0;
	while(string[i] != '\0')
	{
		if (string[i] != 39 && string [i] != '"')
			ft_putchar_fd(string[i], 1);
		i++;
	}
}

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
		//echo_print(string);
	}
	return (0);
}
