/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_expand3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:25:55 by wvan-der          #+#    #+#             */
/*   Updated: 2024/01/19 15:26:21 by wvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishel.h"

int	case_start_with_quote_single(char **res, t_tokens *tok, int *i)
{
	*i += 2;
	while (tok->line[*i] && tok->line[*i] != '\'')
	{
		*res = ft_join(res, tok->line[*i]);
		if (!*res)
			return (0);
		(*i)++;
	}
	(*i)++;
	return (1);
}

int	case_start_with_quote_double(char **res, t_tokens *tok, int *i)
{
	*i += 2;
	while (tok->line[*i] && tok->line[*i] != '"')
	{
		*res = ft_join(res, tok->line[*i]);
		if (!*res)
			return (0);
		(*i)++;
	}
	(*i)++;
	return (1);
}

int	case_start_with_quote(char **res, t_tokens *tok, int *i)
{
	if (tok->line[*i + 1] == '\'')
	{
		if (case_start_with_quote_single(res, tok, i) == 0)
			return (0);
	}
	if (tok->line[*i + 1] == '"')
	{
		if (case_start_with_quote_double(res, tok, i) == 0)
			return (0);
	}
	return (1);
}

int	case_invalid_char(char **res, t_tokens *tok, int *i)
{
	int	a;

	a = 0;
	while (tok->line[*i] && tok->line[*i] != ' ' && (tok->line[*i] != '$'
			|| a == 0))
	{
		*res = ft_join(res, tok->line[*i]);
		if (!*res)
			return (0);
		(*i)++;
		a++;
	}
	return (1);
}

int	append_or_not_1(char **res, char **value, int *i, t_tokens *tok)
{
	if (*value)
	{
		if (append_value(res, *value) == 0)
			return (-1);
		*i = tok->end + 1;
	}
	else
	{
		*i = tok->end + 1;
	}
	return (1);
}
