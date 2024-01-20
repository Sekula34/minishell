/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_expand2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:28:25 by wvan-der          #+#    #+#             */
/*   Updated: 2024/01/19 15:30:23 by wvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishel.h"

int	check_heredoc(char **tokens, int j)
{
	if (j > 0)
	{
		if (tokens[j - 1][0] == '<' && tokens[j - 1][1] == '<')
			return (1);
		else
			return (0);
	}
	return (0);
}

char	*get_key_2(t_tokens *tok, int j)
{
	char	*key;

	key = ft_substr(tok->tokens[j], tok->start, tok->end - tok->start + 1);
	if (!key)
		return (NULL);
	return (key);
}

int	case_invalid_c_2(t_tokens *tok, int *j, int *i)
{
	int	a;

	a = 0;
	while (tok->tokens[*j][*i] && tok->tokens[*j][*i] != ' '
			&& (tok->tokens[*j][*i] != '$' || a == 0))
	{
		tok->fin[*j] = ft_join(&tok->fin[*j], tok->tokens[*j][*i]);
		if (!tok->fin[*j])
			return (0);
		(*i)++;
		a++;
	}
	return (1);
}

int	handle_next_zero_or_dollar_2(t_tokens *tok, int *i, int *j)
{
	if (tok->tokens[*j][*i + 1] == '$' || tok->tokens[*j][*i + 1] == 0)
	{
		tok->fin[*j] = ft_join(&tok->fin[*j], tok->tokens[*j][(*i)++]);
		if (!tok->fin[*j])
			return (0);
		return (1);
	}
	return (2);
}

int	append_or_not_2(char **value, t_tokens *tok, int *i, int *j)
{
	if (*value)
	{
		if (append_value(&tok->fin[*j], *value) == 0)
			return (0);
		*i = tok->end + 1;
	}
	else
	{
		tok->fin[*j] = ft_join(&tok->fin[*j], 0);
		*i = tok->end + 1;
	}
	return (1);
}
