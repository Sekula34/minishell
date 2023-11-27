/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 09:30:00 by fseles            #+#    #+#             */
/*   Updated: 2023/09/06 09:30:03 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;
	int		i;

	d = (char *) dest;
	s = (char *) src;
	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	while (n > 0)
	{
		d[i] = s[i];
		i++;
		n--;
	}
	return (dest);
}

// #include<string.h>
// #include<stdio.h>

// #include<stdlib.h>
// int main () {
// // declare and initialize two array
//    int a[2]={1,2}; 
//    int b[2]={3,4};
//    printf("The data in destination before memcpy occurs\n");
// // display array elements before copy
//    for(int i=0;i<2;i++){
//        printf("%d\t",a[i]);
//    }
// // copy array elements stored in the memory of b to the memory of a
//    ft_memcpy(a, b, sizeof(int)*2);
//    printf("\nThe data in destination after memcpy occurs\n");
// // display array elements after copy
//    for(int i=0;i<2;i++){
//        printf("%d\t",a[i]);
//    }
//    return(0);
// }