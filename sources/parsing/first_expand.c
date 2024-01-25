/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_expand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:53:01 by wvan-der          #+#    #+#             */
/*   Updated: 2024/01/22 12:20:13 by wvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishel.h"

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

int	handle_invalid_or_quote(t_tokens *tok, char **res, int *i)
{
	if (is_quote(tok->line[*i + 1]))
	{
		if (case_start_with_quote(res, tok, i) == 0)
			return (-1);
		return (0);
	}
	if (valid_char(tok->line[*i + 1]) == 0)
	{
		if (case_invalid_char(res, tok, i) == 0)
			return (-1);
		return (0);
	}
	return (1);
}

int	expand_var_1(t_tokens *tok, t_vars *head_ex, int *i, char **res)
{
	char	*key;
	char	*value;
	int		ret;

	value = NULL;
	ret = handle_next_zero_or_dollar_1(tok, i, res);
	if (ret != 1)
		return (ret);
	ret = handle_invalid_or_quote(tok, res, i);
	if (ret != 1)
		return (ret);
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

int	first_expand(t_tokens *tok, t_vars *head_ex, char *line, t_parsing *p)
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
				return (free(res), 0);
		}
		else
		{
			res = ft_join(&res, line[i++]);
			if (!res)
				return (0);
		}
	}
	p->line2 = res;
	return (1);
}
