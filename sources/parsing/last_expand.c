/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_expand.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:14:03 by wvan-der          #+#    #+#             */
/*   Updated: 2023/12/05 17:18:54 by wvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishel.h"
#include <stdlib.h>
#include <string.h>

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

void	set_start_end_2d(char *line, int *i)
{
	(*i)++;
	while (line[*i] && valid_char(line[*i]))
	{
		(*i)++;
	}
}

int	append_value_2d(char **res, char *value, int a)
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

char	**last_expand(t_tokens *tok)
{
	int	i;
	int	j;
	char	*value = strdup("hello");

	j = 0;
	tok->fin = (char **)ft_calloc(tok->token_amount + 1, sizeof(char *));
	reset_struct(tok);
	while (tok->tokens[j])
	{
		i = 0;
		while (tok->tokens[j][i])
		{
			if (tok->tokens[j][i] == '$' && check_heredoc(tok->tokens, j) == 0)
			{
				set_start_end_2d(tok->tokens[j], &i);
				//getvalue
				//check_value(&value);
				append_value_2d(&tok->fin[j], value, j);
			}
			else
				tok->fin[j] = ft_join(&tok->fin[j], tok->tokens[j][i++]);
		}
		j++;
	}
	tok->fin[j] = 0;
	return (tok->fin);
}
