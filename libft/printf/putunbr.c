/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putunbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:20:04 by fseles            #+#    #+#             */
/*   Updated: 2023/09/28 17:20:06 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_nod(unsigned int n)
{
	long	n1;
	int		digits;

	n1 = n;
	digits = 1;
	while (n1 > 9)
	{
		digits++;
		n1 /= 10;
	}
	return (digits);
}

void	putunbr_fd(unsigned int n, int fd)
{
	char	arr[11];
	long	n1;
	int		last_index;

	n1 = n;
	ft_bzero(arr, 11);
	last_index = get_nod(n) - 1;
	while (last_index >= 0)
	{
		arr[last_index] = (n1 % 10) + '0';
		last_index--;
		n1 /= 10;
	}
	ft_putstr_fd(arr, fd);
}
