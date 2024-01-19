/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_fake_redirect.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:09:10 by wvan-der          #+#    #+#             */
/*   Updated: 2024/01/19 15:09:14 by wvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishel.h"

void	doing_conversion(t_tokens *tok, int j)
{
	int	i;

	i = 1;
	while (is_redirect(tok->tokens[j][i]))
	{
		if (tok->tokens[j][i] == '<')
			tok->tokens[j][i] = -1;
		if (tok->tokens[j][i] == '>')
			tok->tokens[j][i] = -2;
		i++;
	}
}

void	convert_fake_redirect(t_tokens *tok)
{
	int	j;

	j = 0;
	while (tok->tokens[j])
	{
		if (is_quote(tok->tokens[j][0]) && is_redirect(tok->tokens[j][1]))
			doing_conversion(tok, j);
		j++;
	}
}

void	convert_fake_redirect_back(char **str)
{
	int	i;

	i = 0;
	while (*str && (*str)[i])
	{
		if ((*str)[i] == -1)
			(*str)[i] = '<';
		if ((*str)[i] == -2)
			(*str)[i] = '>';
		i++;
	}
}
