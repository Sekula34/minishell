/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:07:07 by wvan-der          #+#    #+#             */
/*   Updated: 2023/12/11 18:10:28 by wvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishel.h"


int	count_pipes(char *line)
{
	int	count;
	int i;

	count = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == '|')
			count++;
		i++;
	}
	return (count);
}

char	**split_pipes(t_tokens *tok, char *line)
{
	char **res;
	int i = 0;
	int start = 0;
	int end = 0;
	int a = 0;

	init_token_struct(tok);
	res = (char **)malloc(sizeof(char *) * count_pipes(line) + 1);
	if (!res)
		return (NULL);
	printf("line: %s\n", line);
	while (line[i])
	{
		while (line[i])
			i++;
		printf("%d\n", i);
	}
}
