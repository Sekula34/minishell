/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:39:05 by fseles            #+#    #+#             */
/*   Updated: 2023/11/28 11:39:07 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishel.h"

//prints string on standard output 
//if n_option is 1 pritns newline aswell
//otherwise prints it without newline
//return 0 
int	echo(char *string, int n_option)
{
	if (string == NULL)
		printf("");
	else
		printf("%s", string);
	if (n_option == 1)
		printf("\n");
	return (0);
}
