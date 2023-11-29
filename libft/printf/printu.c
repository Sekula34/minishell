/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printu.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:55:33 by fseles            #+#    #+#             */
/*   Updated: 2023/09/28 16:55:34 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_nod(unsigned int n)
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

int	printu(va_list lista)
{
	unsigned int	number;
	int				value_to_return;

	number = va_arg(lista, unsigned int);
	putunbr_fd(number, 1);
	value_to_return = get_nod(number);
	return (value_to_return);
}
