/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_expand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:53:01 by wvan-der          #+#    #+#             */
/*   Updated: 2024/01/19 14:29:02 by wvan-der         ###   ########.fr       */
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
	char *key;

	key = ft_substr(tok->line, tok->start, tok->end - tok->start + 1);
	if (!key)
		return (NULL);
	return (key);
}

int get_value_var(t_vars *head_ex, char *key, char **value)
{
	t_vars *element;

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

int case_start_with_quote_single(char **res, t_tokens *tok, int *i)
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

int case_start_with_quote_double(char **res, t_tokens *tok, int *i)
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

int case_start_with_quote(char **res, t_tokens *tok, int *i)
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
	while (tok->line[*i] && tok->line[*i] != ' ' && (tok->line[*i] != '$' || a == 0))
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

int	handle_next_zero_or_dollar_1(t_tokens *tok, int *i, char **res)
{
	if (tok->line[(*i) + 1] == 0 || tok->line[(*i) + 1] == '$')
	{
		*res = ft_join(res, tok->line[(*i)++]);
		if (!res)
			return (-1);
		return (0);
	}
	return (1);
}

int	expand_var_1(t_tokens *tok, t_vars *head_ex, int *i, char **res)
{
	char *key;
	char *value;
	int		ret;

	value = NULL;
	ret = handle_next_zero_or_dollar_1(tok, i, res);
	if (ret != 1)
		return (ret);
	if (is_quote(tok->line[*i + 1]))
		return (case_start_with_quote(res, tok, i), 0);
	if (valid_char(tok->line[*i + 1]) == 0)
		return (case_invalid_char(res, tok, i), 0);
	set_start_end(tok, tok->line, (*i) + 1);
	key = check_key(tok);
	if (!key)
		return ((*i)++, -1);
	if (get_value_var(head_ex, key, &value) == 0)
		return (free(key), 0);
	free(key);
	if (append_or_not_1(res, &value, i, tok) == -1)
		return (-1);
	return (1);
}

static void	init_first_expand(int *i, int *j, char **res)
{
	*i = 0;
	*j = 0;
	*res = NULL;
}

char	*first_expand(t_tokens *tok, t_vars *head_ex, char *line)
{
	int		i;
	int		j;
	char	*res;

	init_first_expand(&i, &j, &res);
	tok->line = line;
	reset_struct(tok);
	while (line[i])
	{
		set_quotation(tok, line[i]);
		if (tok->isq == 0 && tok->idq == 0 && line[i] == '$'
			&& go_back_to_check_redirect(tok, line, i) == 0)
		{
			if (expand_var_1(tok, head_ex, &i, &res) == -1)
				return (free(res), NULL);
		}
		else
		{
			res = ft_join(&res, line[i++]);
			if (!res)
				return (NULL);
		}
	}
	return (res);
}
