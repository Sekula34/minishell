/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:07:07 by wvan-der          #+#    #+#             */
/*   Updated: 2024/01/05 14:07:58 by wvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishel.h"

void	ft_free(char ***res, int a)
{
	while (a <= 0)
	{
		free((*res)[a]);
		a--;
	}
	free(*res);
}

int	count_pipes(t_tokens *tok, char *input)
{
	int i = 0;
	int count = 0;

	while (input[i])
	{
		set_quotation(tok, input[i]);
		if (input[i] == '|' && check_quotes(tok) == 0)
			count++;
		i++;
	}
	return (count);
}

char **split_pipes(t_tokens *tok, char *line)
{
	int start = 0;
	int end = 0;
	int count = count_pipes(tok, line) + 1;
	int a = 0;
	char **res;

	reset_struct(tok);
	res = (char **)malloc(sizeof(char *) * (count + 1));
	if (!res)
		return (NULL);
	while (a < count)
	{
		set_quotation(tok, line[end]);
		while (line[end] && (line[end] != '|' || check_quotes(tok) == 1))
			set_quotation(tok,line[end++]);
		res[a] = ft_substr(line, start, end - start);
		if (!res[a])
			return (ft_free(&res, a), NULL);
		a++;
		end++;
		start = end;
	}
	res[a] = NULL;
	return (res);
}
