/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:24:30 by fseles            #+#    #+#             */
/*   Updated: 2023/09/09 15:24:32 by fseles           ###   ########.fr       */
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

void	ft_putnbr_fd(int n, int fd)
{
	char	arr[12];
	long	n1;
	int		last_index;

	n1 = n;
	ft_bzero(arr, 12);
	last_index = get_nod(n) - 1;
	if (n < 0)
	{
		n1 = n1 * (-1);
		last_index = get_nod(n);
	}
	while (last_index >= 0)
	{
		arr[last_index] = (n1 % 10) + '0';
		last_index--;
		n1 /= 10;
	}
	if (n < 0)
		arr[0] = '-';
	ft_putstr_fd(arr, fd);
}

// int main()
// {
// 	ft_putnbr_fd(0,1);
// 	return (0);
// }