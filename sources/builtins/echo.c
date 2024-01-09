/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willem <willem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:39:05 by fseles            #+#    #+#             */
/*   Updated: 2024/01/09 11:37:27 by willem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishel.h"

static void echo_print(char *string)
{
	int i;

	i = 0;
	while(string[i] != '\0')
	{
		if (string[i] != '\'' && string [i] != '"')
			ft_putchar_fd(string[i], 1);
		i++;
	}
}

/* static void echo_print(char *string)
{
	int i;
	int	last_check_quotes;
	t_tokens tok;

	init_tok_struct(&tok);
	i = 0;
	last_check_quotes = 0;
	while (string[i])
	{
		set_quotation(&tok, string[i]);
		if (check_quotes(&tok) != last_check_quotes)
		{
			ft_putchar_fd(string[i], 1);
		}
		else if (check_quotes(&tok))
		{
			ft_putchar_fd(string[i], 1);
		}
		else if (is_quote(string[i]) == 0)
		{
			ft_putchar_fd(string[i], 1);
		}
		last_check_quotes = check_quotes(&tok);
		i++;
	}
} */

//prints string on standard output 
//if n_option is 1 print without newline 
//otherwise prints newline
//return 0 
int	echo(char *string)
{
	if (string == NULL)
	{

	}
	else
	{
		ft_printf("%s", string);
		//echo_print(string);
	}
	return (0);
}
