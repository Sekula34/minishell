/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:25:01 by fseles            #+#    #+#             */
/*   Updated: 2023/09/28 15:25:03 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*hexa_string1(unsigned long number, int option)
{
	char		*string;
	const char	*digits = "0123456789abcdef";
	long long	i;

	i = 0;
	string = ft_calloc(21, sizeof(char));
	if (string == NULL)
		return (NULL);
	if (number == 0)
	{
		string[0] = '0';
		return (string);
	}
	while (number > 0)
	{
		string[i] = digits[number % 16];
		if (option == 1)
			string[i] = ft_toupper(string[i]);
		i++;
		number = number / 16;
	}
	return (string);
}

int	printp(va_list lista)
{
	unsigned long long	p;
	char				*to_print;
	int					i;
	int					value_to_return;

	p = (unsigned long long) va_arg(lista, void *);
	if (p == 0)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	to_print = hexa_string1(p, 0);
	if (to_print == NULL)
		return (-1);
	i = ft_strlen(to_print) - 1;
	ft_putstr_fd("0x", 1);
	value_to_return = i + 3;
	while (i >= 0)
	{
		ft_putchar_fd(to_print[i], 1);
		i--;
	}
	free (to_print);
	return (value_to_return);
}
