/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:41:05 by fseles            #+#    #+#             */
/*   Updated: 2023/09/27 12:41:10 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_valid(char conversion_specifier)
{
	const char	valid_set[] = "cspdiuxX%";
	int			i;

	i = 0;
	while (valid_set[i] != '\0')
	{
		if (conversion_specifier == valid_set[i])
			return (1);
		i++;
	}
	return (0);
}

static void	main_menu(char conversion_specifier, va_list a, long *printed_chars)
{
	if (conversion_specifier == 'c')
		*printed_chars = *printed_chars + printc(a);
	else if (conversion_specifier == 's')
		*printed_chars = *printed_chars + prints(a);
	else if (conversion_specifier == 'p')
		*printed_chars = *printed_chars + printp(a);
	else if (conversion_specifier == 'd' || conversion_specifier == 'i')
		*printed_chars = *printed_chars + printdi(a);
	else if (conversion_specifier == 'u')
		*printed_chars = *printed_chars + printu(a);
	else if (conversion_specifier == 'x')
		*printed_chars = *printed_chars + printx(a, 0);
	else if (conversion_specifier == 'X')
		*printed_chars = *printed_chars + printx(a, 1);
	else if (conversion_specifier == '%')
	{
		ft_putchar_fd('%', 1);
		*printed_chars = *printed_chars + 1;
	}
}

void	looping(const char *format, long *printed_chars, va_list lista)
{
	int	i;

	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			ft_putchar_fd(format[i], 1);
			(*printed_chars)++;
		}
		else
		{
			i++;
			if (!is_valid(format[i]))
			{
				*printed_chars = -1;
				return ;
			}
			main_menu(format[i], lista, printed_chars);
		}
		i++;
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	lista;
	long	printed_chars;

	if (format == NULL)
		return (-1);
	va_start(lista, format);
	printed_chars = 0;
	looping(format, &printed_chars, lista);
	va_end(lista);
	return (printed_chars);
}
