/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:52:38 by fseles            #+#    #+#             */
/*   Updated: 2023/09/07 13:52:40 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	p = malloc (size * nmemb);
	if (p == NULL)
		return (NULL);
	ft_bzero (p, nmemb * size);
	return (p);
}
// #include <stdio.h>
// #include <stdlib.h>

// int main() {
//   int n, i, *ptr, sum = 0;
//   printf("Enter number of elements: ");
//   scanf("%d", &n);

//   ptr = (int*) ft_calloc(n, sizeof(int));
//   if(ptr == NULL) {
//     printf("Error! memory not allocated.");
//     exit(0);
//   }

//   printf("Enter elements: ");
//   for(i = 0; i < n; ++i) {
//     scanf("%d", ptr + i);
//     sum += *(ptr + i);
//   }

//   printf("Sum = %d", sum);
//   free(ptr);
//   return 0;
// }