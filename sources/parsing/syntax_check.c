/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:50:20 by wvan-der          #+#    #+#             */
/*   Updated: 2024/01/25 11:53:43 by wvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishel.h"

int	check_redirect(t_tokens *tok, char *line)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (line && line[i])
	{
		set_quotation(tok, line[i]);
		if (check_quotes(tok) == 0 && is_redirect(line[i]))
		{
			if (check_after_redirect(line, i) == 0)
				return (0);
		}
		i++;
	}
	return (1);
}

static int	redirect_left(int *l_count, int *r_count)
{
	(*l_count)++;
	if (*l_count == 3)
		return (put_error("syntax error near unexpected token `<'\n"), 0);
	if (*r_count != 0)
		return (put_error("syntax error near unexpected token `<'\n"), 0);
	return (1);
}

static int	redirect_right(int *r_count, int *l_count)
{
	(*r_count)++;
	if (*r_count == 3)
		return (put_error("syntax error near unexpected token `>'\n"), 0);
	if (*l_count != 0)
		return (put_error("syntax error near unexpected token `>'\n"), 0);
	return (1);
}

int	check_amount_redirect(t_tokens *tok, char *line)
{
	int	i;
	int	r_count;
	int	l_count;

	i = 0;
	r_count = 0;
	l_count = 0;
	reset_struct(tok);
	while (line && line[i])
	{
		set_quotation(tok, line[i]);
		if (check_quotes(tok) == 0 && line[i] == '<'
			&& redirect_left(&l_count, &r_count) == 0)
			return (0);
		if (check_quotes(tok) == 0 && line[i] == '>'
			&& redirect_right(&r_count, &l_count) == 0)
			return (0);
		if (line[i] != ' ' && line[i] != '\t' && is_redirect(line[i]) == 0)
		{
			l_count = 0;
			r_count = 0;
		}
		i++;
	}
	return (1);
}

int	syntax_check(t_tokens *tok, char *line)
{
	reset_struct(tok);
	if (line[0] == 0)
		return (0);
	if (check_unclosed_quote(tok, line) == 0)
		return (0);
	if (check_pipes(tok, line) == 0)
		return (0);
	if (check_amount_redirect(tok, line) == 0)
		return (0);
	if (check_redirect(tok, line) == 0)
		return (0);
	if (check_after_pipe(tok, line) == 0)
		return (0);
	return (1);
}
