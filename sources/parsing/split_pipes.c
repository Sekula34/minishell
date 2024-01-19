/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:07:07 by wvan-der          #+#    #+#             */
/*   Updated: 2024/01/19 15:33:08 by wvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishel.h"

void	ft_free(char ***res, int a)
{
	a--;
	while (a >= 0)
	{
		free((*res)[a]);
		a--;
	}
	free(*res);
}

int	count_pipes(t_tokens *tok, char *input)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (input && input[i])
	{
		set_quotation(tok, input[i]);
		if (input[i] == '|' && check_quotes(tok) == 0)
			count++;
		i++;
	}
	return (count);
}

static void	init_split_pipes(int *start, int *end, int *a)
{
	*start = 0;
	*end = 0;
	*a = 0;
}

char	**split_pipes(t_tokens *tok, char *line)
{
	int		start;
	int		end;
	int		count;
	int		a;
	char	**res;

	reset_struct(tok);
	count = count_pipes(tok, line) + 1;
	init_split_pipes(&start, &end, &a);
	res = (char **)malloc(sizeof(char *) * (count + 1));
	if (!res)
		return (NULL);
	while (a < count)
	{
		set_quotation(tok, line[end]);
		while (line[end] && (line[end] != '|' || check_quotes(tok) == 1))
			set_quotation(tok, line[end++]);
		res[a] = ft_substr(line, start, end - start);
		if (!res[a])
			return (ft_free(&res, a), NULL);
		a++;
		start = ++end;
	}
	res[a] = NULL;
	return (res);
}
