/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:25:55 by fseles            #+#    #+#             */
/*   Updated: 2023/09/06 14:25:57 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (c + 32);
	}
	return (c);
}
// #include <stdio.h>
// #include <ctype.h>
// int main()
// {
//     char c, result;

//     c = 'M';
//     result = ft_tolower(c);
//     printf("ft_tolower(%c) = %c\n", c, result);

//     c = 'm';
//     result = ft_tolower(c);
//     printf("ft_tolower(%c) = %c\n", c, result);

//     c = '+';
//     result = ft_tolower(c);
//     printf("tolower(%c) = %c\n", c, result);

//     return 0;
// }