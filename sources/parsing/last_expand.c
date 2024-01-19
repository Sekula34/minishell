/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_expand.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:14:03 by wvan-der          #+#    #+#             */
/*   Updated: 2024/01/19 15:30:03 by wvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishel.h"

int	expand_var_2(t_tokens *tok, t_vars *head_ex, int *i, int *j)
{
	char	*key;
	char	*value;
	int		ret;

	value = NULL;
	ret = handle_next_zero_or_dollar_2(tok, i, j);
	if (ret != 2)
		return (ret);
	if (valid_char(tok->tokens[*j][*i + 1]) == 0)
		return (case_invalid_c_2(tok, j, i), 1);
	set_start_end(tok, tok->tokens[*j], (*i) + 1);
	key = get_key_2(tok, *j);
	if (!key)
		return ((*i)++, 0);
	if (get_value_var(head_ex, key, &value) == 0)
		return (free(key), 0);
	if (append_or_not_2(&value, tok, i, j) == 0)
		return (0);
	free(key);
	return (1);
}

void	free_tokens_set_fin(t_tokens *tok)
{
	int	i;

	i = 0;
	while (tok->tokens[i])
	{
		free(tok->tokens[i]);
		i++;
	}
	free(tok->tokens);
	tok->tokens = tok->fin;
}

int	last_expand_logic(t_tokens *tok, t_vars *head_ex, int *j)
{
	int	i;

	i = 0;
	while (tok->tokens[*j] && tok->tokens[*j][i])
	{
		set_quotation(tok, tok->tokens[*j][i]);
		if (tok->tokens[*j][i] == '$' && check_heredoc(tok->tokens, *j) == 0
				&& tok->isq == 0 && tok->idq == 1)
		{
			if (expand_var_2(tok, head_ex, &i, j) == 0)
				return (0);
		}
		else
		{
			tok->fin[*j] = ft_join(&tok->fin[*j], tok->tokens[*j][i++]);
			if (!tok->fin[*j])
				return (0);
		}
	}
	(*j)++;
	return (1);
}

int	last_expand(t_tokens *tok, t_vars *head_ex)
{
	int	i;
	int	j;

	j = 0;
	tok->fin = (char **)ft_calloc(tok->token_amount + 1, sizeof(char *));
	if (!tok->fin)
		return (0);
	reset_struct(tok);
	while (tok->tokens[j])
	{
		if (last_expand_logic(tok, head_ex, &j) == 0)
			return (0);
	}
	tok->fin[j] = 0;
	free_tokens_set_fin(tok);
	return (1);
}
