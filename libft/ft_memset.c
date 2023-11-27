/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:05:56 by fseles            #+#    #+#             */
/*   Updated: 2023/09/05 15:05:58 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*p;
	int		i;

	p = (char *) s;
	i = 0;
	while (n > 0)
	{
		p[i] = c;
		i++;
		n--;
	}
	return (s);
}
// #include <stdlib.h>

// #include <string.h>
// #include <stdio.h>
// int	main()
// {
//     char str[50] = "GeeksForGeeks is for programming geeks.";
//     printf("\nBefore memset(): %s\n", str);

//     // Fill 8 characters starting from str[13] with '.'
//     memset(str, '.', 3*sizeof(char));

//     printf("After memset():  %s \n\n", str);
// 	char str1[50] = "GeeksForGeeks is for programming geeks.";
//     printf("\nBefore memset(): %s\n", str1);

//     // Fill 8 characters starting from str[13] with '.'
//     ft_memset(str1, '.', 3*sizeof(char));

//     printf("After memset():  %s", str1);
// 	int number = 67; 
// 	int *pointer; 
// 	pointer = &number; 
// 	printf("\nBefore memset(): %d\n", number);
// 	memset(pointer, '2', 1*sizeof(int));
// 	printf("After memset():  %d\n\n", number);
// 	int number1 = 67; 
// 	int *pointer1; 
// 	pointer1 = &number1; 
// 	printf("\nBefore memset(): %d\n", number1);
// 	ft_memset(pointer1, '2', 1*sizeof(int));
// 	printf("After memset():  %d \n\n", number1);
// 	char arr[3];
// 	ft_memset(arr, '$', 2);
// 	printf("%c %c %c", arr[0], arr[1], arr[2]);
// 	printf("\n%lu", sizeof(char)); 
//     return 0;
// }