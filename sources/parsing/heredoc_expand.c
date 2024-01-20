/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_expand.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:09:34 by wvan-der          #+#    #+#             */
/*   Updated: 2024/01/20 13:59:36 by wvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishel.h"

char	*get_key_heredoc(t_shell *shell, int i, char **res, t_tokens *tok_h)
{
	char	*key;

	tok_h->start = i;
	while (tok_h->line[i] && valid_char((tok_h->line)[i]))
	{
		i++;
	}
	tok_h->end = i - 1;
	if (tok_h->end < tok_h->start)
		tok_h->end++;
	key = ft_substr(tok_h->line, tok_h->start, tok_h->end - tok_h->start + 1);
	if (!key)
		return (NULL);
	return (key);
}

int	expand_var_heredoc(t_shell *shell, int *i, char **res, t_tokens *tok_h)
{
	char *key;
	char *value;

	value = NULL;
	// if (tok_h->line[*i + 1] == '$')
	// 	return ((*i)++, 0);
	if (tok_h->line[*i + 1] == 0 || is_quote(tok_h->line[*i + 1]) || tok_h->line[*i + 1] == '$')
	{
		*res = ft_join(res, tok_h->line[(*i)++]);
		if (!*res)
			return (-1);
		return (0);
	}
	key = get_key_heredoc(shell, (*i) + 1, res, tok_h);
	if (!key)
		return ((*i)++, -1);
	//ft_printf("key %s\n", key);
	if (get_value_var(shell->head_ex, key, &value) == 0)
		return (free(key), 0);
	free(key);
	if (value && append_value(res, value) == 0)
		return (-1);
	*i = tok_h->end + 1;
	return (1);
}

int	heredoc_expand(t_shell *shell, char *line, char **res)
{
	t_tokens tok_h;
	int i;

	i = 0;
	init_tok_struct(&tok_h);
	tok_h.line = line;
	*res = NULL;
	while ((line)[i])
	{
		if ((line)[i] == '$')
		{
			if (expand_var_heredoc(shell, &i, res, &tok_h) == -1)
				return (free(*res), 0);
		}
		else
		{
			*res = ft_join(res, tok_h.line[i++]);
			if (!*res)
				return (0);
		}
	}
	//ft_printf("res %s\n", *res);
	return (1);
}

