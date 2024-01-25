/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_check2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:34:31 by wvan-der          #+#    #+#             */
/*   Updated: 2024/01/25 14:12:08 by wvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishel.h"

int	check_unclosed_quote(t_tokens *tok, char *line)
{
	int	i;
	int	single_count;
	int	double_count;

	i = 0;
	single_count = 0;
	double_count = 0;
	while (line && line[i])
	{
		set_quotation(tok, line[i]);
		if (check_quotes(tok) == 0)
		{
			if (line[i] == '"')
				double_count++;
			if (line[i] == '\'')
				single_count++;
		}
		i++;
	}
	if (tok->isq == 1)
		return (put_error("syntax error near unexpected token `''\n"), 0);
	if (tok->idq == 1)
		return (put_error("syntax error near unexpected token `\"'\n"), 0);
	return (1);
}

int	check_pipes(t_tokens *tok, char *line)
{
	int	flag;
	int	i;

	flag = 0;
	i = 0;
	reset_struct(tok);
	while (line && line[i])
	{
		set_quotation(tok, line[i]);
		if (check_quotes(tok) == 0 && line[i] != '|' && line[i] != ' ')
			flag = 1;
		if (check_quotes(tok) == 0 && line[i] == '|')
		{
			if (flag == 0)
				return (put_error("syntax error near token `|'\n"), 0);
			flag = 0;
		}
		i++;
	}
	return (1);
}

int	check_after_redirect(char *line, int i)
{
	int	flag;

	flag = 0;
	while (line && line[i] && line[i] != '|')
	{
		while (is_redirect(line[i]))
			i++;
		while (line[i] && line[i] != '|')
		{
			if (line[i] != ' ')
				return (1);
			i++;
		}
		if (line && line[i] && line[i] == '|')
			return (put_error("syntax error near end of cmd\n"), 0);
		if (line && line[i])
			i++;
	}
	return (put_error("syntax error near end of cmd\n"), 0);
}

int	check_after_pipe(t_tokens *tok, char *line)
{
	int	i;

	i = 0;
	reset_struct(tok);
	while (line && line[i])
	{
		set_quotation(tok, line[i]);
		if (line[i] == '|' && check_quotes(tok) == 0)
		{
			i++;
			while (line[i] == ' ')
				i++;
			if (line[i] == 0)
				return (put_error("after pipe error\n"), 0);
		}
		i++;
	}
	return (1);
}
