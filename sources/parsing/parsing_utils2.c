/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:01:46 by wvan-der          #+#    #+#             */
/*   Updated: 2023/12/13 17:31:46 by wvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishel.h"

void	init_parsing_struct(t_tokens *tok)
{
	tok->isq = 0;
	tok->idq = 0;
	tok->tok_i = 0;
	tok->redirect_count = 0;
	tok->flag = 0;
	tok->i = 0;
	tok->j = 0;
	tok->start = 0;
	tok->end = 0;
	tok->redirect_flag = 0;
	tok->tokens = NULL;
	tok->fin = NULL;
	tok->token_amount = 0;
	tok->line = NULL;
	tok->key = NULL;
	tok->value = NULL;
}

void	reset_struct(t_tokens *tok)
{
	tok->isq = 0;
	tok->idq = 0;
	tok->redirect_count = 0;
	tok->flag = 0;
	tok->i = 0;
	tok->j = 0;
	tok->start = 0;
	tok->end = 0;
	tok->redirect_flag = 0;
}

void	check_value(char **value)
{
	int	i;

	i = 0;
	if (!*value)
		return ;
	while ((*value)[i])
	{
		if ((*value)[i] == '<')
			(*value)[i] = -1;
		else if ((*value)[i] == '>')
			(*value)[i] = -2;
		i++;
	}
}

int	valid_char(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c >= 'A' && c <= 'Z')
		return (1);
	if (c >= '0' && c <= '9')
		return (1);
	if (c == '_')
		return (1);
/* 	if (c == '"')
		return (1);
	if (c == '\'')
		return (1); */
	return (0);
}

void	init_make_token(int *a, int *i)
{
	*a = 0;
	*i = 0;
}
