/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_expand2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:23:39 by wvan-der          #+#    #+#             */
/*   Updated: 2024/01/19 15:24:18 by wvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishel.h"

int	set_start_end(t_tokens *tok, char *line, int i)
{
	tok->start = i;
	if (line[i] == '?')
	{
		tok->end = i;
		return (1);
	}
	while (line[i] && valid_char(line[i]))
	{
		i++;
	}
	tok->end = i - 1;
	if (tok->end < tok->start)
	{
		tok->end++;
	}
	return (1);
}

int	append_value(char **res, char *value)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (value[i])
	{
		*res = ft_join(res, value[i]);
		if (!*res)
			return (0);
		i++;
	}
	return (1);
}

int	go_back_to_check_redirect(t_tokens *tok, char *line, int i)
{
	while (i > 0 && ((line[i] != ' ' && line[i] != '\t')
			|| tok->isq == 1 || tok->idq == 1))
	{
		set_quotation(tok, line[i]);
		if (line[i] == '<' || line[i] == '>')
			return (1);
		i--;
	}
	while (i > 0 && (line[i] == ' ' || line[i] == '\t'))
	{
		set_quotation(tok, line[i]);
		i--;
	}
	if (line[i] == '<' || line[i] == '>')
		return (1);
	else
		return (0);
}

char	*check_key(t_tokens *tok)
{
	char	*key;

	key = ft_substr(tok->line, tok->start, tok->end - tok->start + 1);
	if (!key)
		return (NULL);
	return (key);
}

int	get_value_var(t_vars *head_ex, char *key, char **value)
{
	t_vars	*element;

	element = get_element(key, head_ex);
	if (!element)
	{
		*value = NULL;
		return (1);
	}
	*value = element->value;
	check_value(value);
	return (1);
}
