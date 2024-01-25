/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:09:39 by fseles            #+#    #+#             */
/*   Updated: 2024/01/22 15:50:28 by wvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s && s[i] != '\0')
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

// int main()
// {
// 	char s[] = "Jel ovo radi pliz reci da da ";
// 	ft_putstr_fd(s, 0);
// 	return (0);
// }
