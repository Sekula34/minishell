/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:23:33 by fseles            #+#    #+#             */
/*   Updated: 2023/09/06 16:23:35 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*sa;
	unsigned char	*sb;

	sa = (unsigned char *) s1;
	sb = (unsigned char *) s2;
	i = 0;
	while ((n - i) > 0 && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (sa[i] != sb[i])
			return ((int)(sa[i] - sb[i]));
		i++;
	}
	return (0);
}
// #include<stdlib.h>
// #include <stdio.h>
// #include <string.h>
// int main () {
//    char str1[20];
//    char str2[20];
//    int result;
//    //Assigning the value to the string str1
//    strcpy(str1, "test\200");
//    //Assigning the value to the string str2
//    strcpy(str2, "test\0");
//    //This will compare the first 3 characters
//    result = ft_strncmp(str1, str2, 5);
//    if(result > 0) {
//       printf("ASCII value of 
//first unmatched character of str1 is greater than str2");
//    } else if(result < 0) {
//       printf("ASCII value of first 
//unmatched character of str1 is less than str2");
//    } else {
//       printf("Both the strings str1 and str2 are equal");
//    }
//    return 0;
// }