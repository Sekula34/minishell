/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:32:14 by fseles            #+#    #+#             */
/*   Updated: 2023/09/05 12:32:20 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
// #include <ctype.h>
// #include <stdio.h>
// int main()
// {
//     printf("Original function value is %d\n", ft_isprint('0'));
//     printf("Mycopyyy function value is %d\n\n", isprint('0'));
//     printf("Original function value is %d\n", ft_isprint('9'));
//     printf("Mycopyyy function value is %d\n\n", isprint('9'));
//     printf("Original function value is %d\n", ft_isprint(' '));
//     printf("Mycopyyy function value is %d\n\n", isprint(' '));
//     printf("Original function value is %d\n", ft_isprint('a'));
//     printf("Mycopyyy function value is %d\n\n", isprint('a'));
//     printf("Original function value is %d\n", ft_isprint('A'));
//     printf("Mycopyyy function value is %d\n\n", isprint('A'));
//     printf("Original function value is %d\n", ft_isprint('\n'));
//     printf("Mycopyyy function value is %d\n\n", isprint('\n'));
//     printf("Original function value is %d\n", ft_isprint(100));
//     printf("Mycopyyy function value is %d\n\n", isprint(100));
//     return (0);
// }