/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_expand.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:14:03 by wvan-der          #+#    #+#             */
/*   Updated: 2024/01/16 15:13:11 by wvan-der         ###   ########.fr       */
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

/* void	set_start_end_2d(t_tokens *tok, char *line, int *i)
{
	(*i)++;
	tok->start = *i;
	while (line[*i] && valid_char(line[*i]))
	{
		(*i)++;
	}
	tok->end = *i - 1;
	if (tok->end < tok->start)
	{
		tok->end++;
	}
	if (line[*i] && (line[*i] == 0 || line[*i] == ' '))
		puts("problem");
	//printf("start c: %c, end c: %c\n", line[tok->start], line[tok->end]);
} */

/* int	append_value_2d(char **res, char *value)
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
} */

/* char *get_var_value_2d(t_tokens *tok, t_vars *head_ex, char *line)
{
	t_vars *element;
	char *key;

	key = ft_substr(line, tok->start, tok->end - tok->start + 1);
	if (!key)
		return (NULL);
	if (!key[0] || key[0] == '\'' || key[0] == '"')
		return (NULL);
	printf("key: %s\n", key);
	puts("?");

	element = get_element(key, head_ex);
	free(key);
	if (!element)
		return (NULL);
	return (element->value);
} */

/* int	put_value_2d(t_tokens *tok, t_vars *head_ex, char *line, char **res, int j)
{
	char *value;

	j += 0;
	value = get_var_value(tok, head_ex, line);
	if (!value)
	{
 		if (j != 0 && (tok->tokens[j - 1][0] == '<' || tok->tokens[j - 1][0] == '>'))
		{
			*res = ft_join(res, '"');
			return (1);
		} 
		puts("this");
		return (0);
	}
	check_value(&value);
	append_value(res, value);
	return (1);
} */

char *get_key_2(t_tokens *tok, int j)
{
	char *key;

	key = ft_substr(tok->tokens[j], tok->start, tok->end - tok->start + 1);
	if (!key)
		return (NULL);
	return (key);
}

int	case_invalid_c_2(t_tokens *tok, int *j, int *i)
{
	int a;

	a = 0;
	while (tok->tokens[*j][*i] && tok->tokens[*j][*i] != ' '
			&& (tok->tokens[*j][*i] != '$' || a == 0))
	{
		tok->fin[*j] = ft_join(&tok->fin[*j], tok->tokens[*j][*i]);
		if (!tok->fin[*j])
		{
			//free
			return(0);
		}
		(*i)++;
		a++;
	}
	return (1);
}

int	expand_var_2(t_tokens *tok, t_vars *head_ex, int *i, int *j)
{
	//printf("-%s-\n", tok->tokens[*j]);
	char *key;
	char *value;

	if (tok->tokens[*j][*i + 1] == '$')
		return ((*i)++, 0);
 	if (valid_char(tok->tokens[*j][*i + 1]) == 0)
		return (case_invalid_c_2(tok, j, i), 0);
	set_start_end(tok, tok->tokens[*j], (*i) + 1);
	key = get_key_2(tok, *j);
	if (!key)
		return ((*i)++, 0);
	//printf("key:%s-\n", key);
	if (get_value_var(head_ex, key, &value) == 0)
		return (free(key), 0);
	//printf("value:%s-\n", value);
	if (value)
	{
		append_value(&tok->fin[*j], value);
		*i = tok->end + 1;
	}
	else
	{
		tok->fin[*j] = ft_join(&tok->fin[*j], 0);
		(*j)++;
	}
	free(key);
	return (1);
}


void free_tokens_set_fin(t_tokens *tok)
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

int last_expand(t_tokens *tok, t_vars *head_ex)
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
		i = 0;
		while (tok->tokens[j][i])
		{
			set_quotation(tok, tok->tokens[j][i]);
			if (tok->tokens[j][i] == '$' && check_heredoc(tok->tokens, j) == 0 && tok->isq == 0)
			{
				if (expand_var_2(tok, head_ex, &i, &j) == 0)
					return (0);
			}
			else
			{
				tok->fin[j] = ft_join(&tok->fin[j], tok->tokens[j][i++]);
				if (!tok->fin[j])
					return (0);
			}
		}
		j++;
	}
	tok->fin[j] = 0;
	free_tokens_set_fin(tok);
	return (1);
}
