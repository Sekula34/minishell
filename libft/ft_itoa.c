/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:20:55 by fseles            #+#    #+#             */
/*   Updated: 2023/09/08 16:20:57 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_nod(int n)
{
	long	n1;
	int		digits;

	n1 = n;
	if (n1 < 0)
		n1 = n1 * (-1);
	digits = 1;
	while (n1 > 9)
	{
		digits++;
		n1 /= 10;
	}
	return (digits);
}

static char	*digit_filler(char *p, long number, int minus, int nod)
{
	int	i;

	i = 0;
	if (minus == 1)
	{
		p[0] = '-';
		i++;
	}
	while (nod > i)
	{
		p[nod - 1] = (number % 10) + '0';
		number /= 10;
		nod--;
	}
	return (p);
}

char	*ft_itoa(int n)
{
	char	*p;
	int		nod;
	long	n1;
	int		minus;

	minus = 0;
	n1 = n;
	nod = get_nod(n);
	if (n < 0)
	{
		nod++;
		n1 = n1 * (-1);
		minus = 1;
	}
	p = ft_calloc(nod + 1, sizeof(char));
	if (p == NULL)
		return (NULL);
	digit_filler(p, n1, minus, nod);
	return (p);
}

// #include <stdio.h>

// int main()
// {
// 	char *p;

// 	p = ft_itoa(937);
// 	printf("%s", p);
// 	free(p);
// 	return (0); 
// }