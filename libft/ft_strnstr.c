/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:09:22 by fseles            #+#    #+#             */
/*   Updated: 2023/09/06 18:09:25 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	char	*sit;

	sit = (char *) big;
	if (big == NULL)
		sit[1] = '3';
	if (little[0] == '\0')
		return ((char *)big);
	if (len == 0)
		return (NULL);
	i = 0;
	while (i < (len + 1 - ft_strlen(little)) && *big != '\0')
	{
		if (ft_strncmp(big, little, ft_strlen(little)) == 0)
			return ((char *) big);
		big++;
		i++;
	}
	return (NULL);
}

// #include<stdio.h>
// #include<stdlib.h>
// int main()
// {
// 	// const char *largestring = "Foo Bar Baz";
// 	// const char *smallstring = "Bar";
//     char *ptr;

//     ptr = ft_strnstr("aaxx", "xx", 4);
// 	printf("%s", ptr);

// 	return (0);
// }