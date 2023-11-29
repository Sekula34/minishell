/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:04:30 by fseles            #+#    #+#             */
/*   Updated: 2023/09/05 10:05:43 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (1);
	}
	return (0);
}

static int	ft_islower(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (1);
	}
	return (0);
}

int	ft_isalpha(int c)
{
	return (ft_isupper(c) || ft_islower(c));
}
// #include <ctype.h>
// #include <stdio.h>
// int	main ()
// {
//     //int isalpha(int c); // ekvivaletno isupper || islower
//     //int isupper(int c);
//     printf("%d", isalpha('3')); 

//     printf("Original function value is %d\n", ft_isalpha('a'));
//     printf("Mycopyyy function value is %d\n\n", isalpha('a'));

//     printf("Original function value is %d\n", ft_isalpha('b'));
//     printf("Mycopyyy function value is %d\n\n", isalpha('b'));

//     printf("Original function value is %d\n", ft_isalpha('z'));
//     printf("Mycopyyy function value is %d\n\n", isalpha('z'));

//     printf("Original function value is %d\n", ft_isalpha('a'));
//     printf("Mycopyyy function value is %d\n\n", isalpha('a'));

//     printf("Original function value is %d\n", ft_isalpha(0));
//     printf("Mycopyyy function value is %d\n\n", isalpha(0));

//     printf("Original function value is %d\n", ft_isalpha('A'));
//     printf("Mycopyyy function value is %d\n\n", isalpha('A'));

//     printf("Original function value is %d\n", ft_isalpha('\n'));
//     printf("Mycopyyy function value is %d\n\n", isalpha('\n'));

//     return (0);
// }
