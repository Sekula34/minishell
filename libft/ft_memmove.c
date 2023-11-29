/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:24:29 by fseles            #+#    #+#             */
/*   Updated: 2023/09/06 10:24:32 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;

	d = (char *) dest;
	s = (char *) src;
	if (dest <= src || ((dest) > (src + n)))
	{
		return (ft_memcpy(dest, src, n));
	}
	else
	{
		while (n > 0)
		{
			d[n - 1] = s[n - 1];
			n--;
		}
		return (dest);
	}
}
// /* memmove example */
// #include <stdio.h>
// #include <string.h>

// int main ()
// {
//   char str[] = "memmove can be very useful......";
//   ft_memmove (str+20,str+15,11);
//   puts (str);
//   return 0;
// }
