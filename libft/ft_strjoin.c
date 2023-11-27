/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 09:22:58 by fseles            #+#    #+#             */
/*   Updated: 2023/09/08 09:23:00 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size_new_string;
	char	*p;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	size_new_string = ft_strlen(s1) + ft_strlen(s2) + 1;
	p = ft_calloc(size_new_string, sizeof(char));
	if (p == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		p[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		p[i] = s2[j];
		j++;
		i++;
	}
	return (p);
}
// #include<stdio.h>
// int main()
// {
// 	char s[] = "Filip ";
// 	char s1[] = "Seles";
// 	char *p1; 

// 	p1 = ft_strjoin(s, s1); 
// 	printf("%s", p1); 
// 	free(p1); 
// 	return (0); 
// }