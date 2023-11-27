/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:30:15 by fseles            #+#    #+#             */
/*   Updated: 2023/09/05 17:30:18 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_bzero(void *s, size_t n)
{
	char	*p;
	int		i;

	i = 0;
	p = (char *) s;
	while (n > 0)
	{
		p[i] = '\0';
		i++;
		n--;
	}
}

// #include<stdlib.h>
// #include <strings.h>
// #include <stdio.h>
// int main()
// {
// 	char string[50]= "helllowowoijweoijwoie"; 
// 	char string1[50] = "helllowowoijweoijwoie"; 
// 	void *p; 
// 	void *p1; 
// 	p = string; 
// 	p1 = string1; 
// 	bzero(p + 3, 10); 
// 	ft_bzero(p1 + 3, 10); 
// 	int i = 0; 
// 	while (i < 20)
// 	{
// 		printf("%c" , string[i]); 
// 		i++; 
// 	}
// 	printf("\n");
// 	i = 0; 
// 	while (i < 20)
// 	{
// 		printf("%c" , string1[i]); 
// 		i++; 
// 	}
// }