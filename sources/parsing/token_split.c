/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:58:30 by wvan-der          #+#    #+#             */
/*   Updated: 2024/01/19 15:56:21 by wvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishel.h"

int	count_token(t_tokens *tok, char *line)
{
	reset_struct(tok);
	while (line[tok->i])
	{
		while (line[tok->i] && is_white_space(line[tok->i]) == 1)
			tok->i++;
		while (line[tok->i] && (is_white_space(line[tok->i]) == 0
				|| check_quotes(tok)) && is_redirect(line[tok->i]) == 0)
		{
			set_quotation(tok, line[tok->i++]);
			tok->flag = 1;
		}
		if (tok->flag && tok->isq == 0 && tok->idq == 0)
			move_counter(tok);
		while (line[tok->i] && is_redirect(line[tok->i]))
		{
			tok->flag = 1;
			tok->redirect_count++;
			if (tok->redirect_count == 2)
				move_counter(tok);
			tok->i++;
		}
		if (tok->flag && tok->isq == 0 && tok->idq == 0)
			move_counter(tok);
	}
	return (tok->tok_i);
}

int	tokenize_redirect(t_tokens *tok, char *line, int *i, int *a)
{
	tok->redirect_count++;
	tok->tokens[*a] = ft_join(&(tok->tokens[*a]), line[*i]);
	if (!tok->tokens[*a])
		return (0);
	if (tok->redirect_count == 2 && is_redirect(line[*i + 1])
		&& check_quotes(tok) == 0)
	{
		(*a)++;
		tok->redirect_count = 0;
	}
	if (is_redirect(line[*i + 1]) == 0)
		tok->redirect_count = 0;
	(*i)++;
	return (1);
}

int	copy_text(t_tokens *tok, char *line, int *i, int a)
{
	set_quotation(tok, line[*i]);
	tok->tokens[a] = ft_join(&(tok->tokens[a]), line[*i]);
	if (!tok->tokens[a])
		return (0);
	(*i)++;
	return (1);
}

int	make_token_logic(t_tokens *tok, char *line, int *i, int *a)
{
	while (line[*i] && is_white_space(line[*i]) == 1 && check_quotes(tok) == 0)
		(*i)++;
	while (line[*i] && (is_white_space(line[*i]) == 0
			|| check_quotes(tok)) && is_redirect(line[*i]) == 0)
	{
		if (copy_text(tok, line, i, *a) == 0)
			return (0);
	}
	if (tok->tokens[*a] && tok->isq == 0 && tok->idq == 0)
		(*a)++;
	while (line[*i] && is_redirect(line[*i]))
	{
		if (tokenize_redirect(tok, line, i, a) == 0)
			return (0);
	}
	if (tok->tokens[*a] && tok->isq == 0 && tok->idq == 0)
		(*a)++;
	return (1);
}

int	make_token(t_tokens *tok, char *line)
{
	int		i;
	int		a;

	if (!line)
		return (0);
	init_make_token(&a, &i);
	tok->tokens = ft_calloc(count_token(tok, line) + 1, sizeof(char *));
	if (!tok->tokens)
		return (0);
	reset_struct(tok);
	while (line[i])
	{
		if (make_token_logic(tok, line, &i, &a) == 0)
			return (0);
	}
	tok->tokens[a] = 0;
	return (1);
}
