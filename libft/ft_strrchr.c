/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:11:26 by fseles            #+#    #+#             */
/*   Updated: 2023/09/06 15:11:28 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	long long	length_s;

	length_s = ft_strlen(s);
	while (length_s >= 0)
	{
		if (s[length_s] == (char) c)
			return ((char *)(s + length_s));
		length_s --;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>
// #include<stdlib.h>

// int main () {
//    //int len;
//    const char str[] = "teste";
//    const char ch = 'x';
//    char *ret;

//    ret = ft_strrchr(str, ch);

//    printf("String after |%c| is - |%s|\n", ch, ret);

// 	size_t size = (size_t)-1;
// 	printf("%zu", size);

//    return(0);
// }