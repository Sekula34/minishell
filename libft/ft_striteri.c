/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 14:27:36 by fseles            #+#    #+#             */
/*   Updated: 2023/09/09 14:27:38 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		(*f)(i, &s[i]);
		i++;
	}
}
// #include<stdio.h>
// void my_function(unsigned int n, char* c)
// {
// 	printf("%d and %p \n", n, c);
// 	//return ('a');
// }

// #include<stdlib.h>

// int main()
// {
// 	ft_striteri("Vidi charactera", my_function);
// 	return (0);
// }