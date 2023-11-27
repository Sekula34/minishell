/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 17:33:56 by fseles            #+#    #+#             */
/*   Updated: 2023/09/08 17:33:59 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	unsigned int	i;
	char			*p;

	i = 0;
	p = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (p == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		p[i] = (*f)(i, s[i]);
		i++;
	}
	return (p);
}

// #include<stdio.h>
// char my_function(unsigned int n, char c)
// {
// 	printf("%d and %c \n", n, c);
// 	return ('a');
// }

// #include<stdlib.h>

// int main()
// {
// 	ft_strmapi("Hello", my_function);
// 	return (0);
// }