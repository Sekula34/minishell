/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:19:27 by fseles            #+#    #+#             */
/*   Updated: 2023/09/06 14:19:29 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (c - 32);
	}
	return (c);
}
// #include <stdio.h>
// #include <ctype.h>
// int main() {
//     char c;

//     c = 'm';
//     printf("%c -> %c", c, ft_toupper(c));

//     c = 'D';
//     printf("\n%c -> %c", c, ft_toupper(c));

//     c = '9';
//     printf("\n%c -> %c", c, ft_toupper(c));
//     return 0;
// }
