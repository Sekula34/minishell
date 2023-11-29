/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printdi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:31:05 by fseles            #+#    #+#             */
/*   Updated: 2023/09/28 16:31:07 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	printdi(va_list lista)
{
	int	number;
	int	value_to_return;

	number = va_arg(lista, int);
	ft_putnbr_fd(number, 1);
	value_to_return = get_nod(number);
	if (number < 0)
		return (value_to_return + 1);
	return (value_to_return);
}
