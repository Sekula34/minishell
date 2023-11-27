/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:57:14 by fseles            #+#    #+#             */
/*   Updated: 2023/09/05 11:57:19 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
// #include <ctype.h>
// #include <stdio.h>
// int	main()
// {
//     printf("Original function value is %d\n", ft_isalnum('a'));
//     printf("Mycopyyy function value is %d\n\n", isalnum('a'));

//     printf("Original function value is %d\n", ft_isalnum('B'));
//     printf("Mycopyyy function value is %d\n\n", isalnum('B'));

//     printf("Original function value is %d\n", ft_isalnum('k'));
//     printf("Mycopyyy function value is %d\n\n", isalnum('k'));

//     printf("Original function value is %d\n", ft_isalnum('Z'));
//     printf("Mycopyyy function value is %d\n\n", isalnum('Z'));

//     printf("Original function value is %d\n", ft_isalnum(0));
//     printf("Mycopyyy function value is %d\n\n", isalnum(0));

//     printf("Original function value is %d\n", ft_isalnum('3'));
//     printf("Mycopyyy function value is %d\n\n", isalnum('3'));

//     printf("Original function value is %d\n", ft_isalnum('\n'));
//     printf("Mycopyyy function value is %d\n\n", isalnum('\n'));
// }
