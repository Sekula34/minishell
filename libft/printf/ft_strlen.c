/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:00:33 by fseles            #+#    #+#             */
/*   Updated: 2023/09/05 14:00:38 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// int main ()
// {
// 	if(ft_strlen("Filip") == strlen("Filip"))
// 	{
// 		printf("isti su \n"); 
// 	}
// 	else 
// 	{
// 		printf("nisu \n"); 
// 	}

// 	if(ft_strlen("") == strlen(""))
// 	{
// 		printf("isti su \n"); 
// 	}
// 	else 
// 	{
// 		printf("nisu \n"); 
// 	}
// }