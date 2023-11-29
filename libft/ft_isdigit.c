/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:27:58 by fseles            #+#    #+#             */
/*   Updated: 2023/09/05 11:28:03 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
// #include <ctype.h>
// #include <stdio.h>
// int main()
// {
//     printf("Original function value is %d\n", ft_isdigit('0'));
//     printf("Mycopyyy function value is %d\n\n", isdigit('0'));
//     printf("Original function value is %d\n", ft_isdigit('9'));
//     printf("Mycopyyy function value is %d\n\n", isdigit('9'));
//     printf("Original function value is %d\n", ft_isdigit('4'));
//     printf("Mycopyyy function value is %d\n\n", isdigit('4'));
//     printf("Original function value is %d\n", ft_isdigit('a'));
//     printf("Mycopyyy function value is %d\n\n", isdigit('a'));
//     printf("Original function value is %d\n", ft_isdigit(9));
//     printf("Mycopyyy function value is %d\n\n", isdigit(9));
//     printf("Original function value is %d\n", ft_isdigit(50));
//     printf("Mycopyyy function value is %d\n\n", isdigit(50));
//     return (0);
// }