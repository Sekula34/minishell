/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:15:37 by fseles            #+#    #+#             */
/*   Updated: 2023/09/05 12:15:42 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
	{
		return (1);
	}
	return (0);
}

// #include <ctype.h>
// #include <stdio.h>
// int main()
// {

//     printf("Original function value is %d\n", ft_isascii('0'));
//     printf("Mycopyyy function value is %d\n\n", __isascii('0'));

//     printf("Original function value is %d\n", ft_isascii('9'));
//     printf("Mycopyyy function value is %d\n\n", __isascii('9'));

//     printf("Original function value is %d\n", ft_isascii('4'));
//     printf("Mycopyyy function value is %d\n\n", __isascii('4'));

//     printf("Original function value is %d\n", ft_isascii('\n'));
//     printf("Mycopyyy function value is %d\n\n", __isascii('\n'));

//     printf("Original function value is %d\n", ft_isascii(-127));
//     printf("Mycopyyy function value is %d\n\n", __isascii(-127));

//     printf("Original function value is %d\n", ft_isascii(200));
//     printf("Mycopyyy function value is %d\n\n", __isascii(200));
//     return (0);
// }