/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:23:29 by fseles            #+#    #+#             */
/*   Updated: 2023/09/07 10:23:31 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if (c == ' ' || c == '\f' || c == '\n')
		return (1);
	if (c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	long	result;

	sign = 1;
	i = 0;
	result = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		result = result * 10 + (nptr[i] - 48);
		i++;
	}
	return ((int)(result * sign));
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h> 
// int main()
// {
//     int val;
//     char strn1[] = "       2147483647";
//     val = ft_atoi(strn1);
//     printf("String value = %s\n", strn1);
//     printf("Integer value = %d\n", val);
//     char strn2[] = "GeeksforGeeks";
//     val = ft_atoi(strn2);
//     printf("String value = %s\n", strn2);
//     printf("Integer value = %d\n", val);
//     return (0);
// }