/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:55:37 by wvan-der          #+#    #+#             */
/*   Updated: 2024/01/05 17:45:35 by wvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishel.h"

void	set_quotation(t_tokens *tok, char c)
{
	if (c == '"')
	{
		if (tok->isq == 1)
			return ;
		if (tok->idq == 0)
			tok->idq = 1;
		else if (tok->idq == 1)
			tok->idq = 0;
	}
	if (c == '\'')
	{
		if (tok->idq == 1)
			return ;
		if (tok->isq == 0)
			tok->isq = 1;
		else if (tok->isq == 1)
			tok->isq = 0;
	}
}

int	get_len(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_join(char **str, char c)
{
	int		i;
	int		j;
	int		len;
	char	*temp;

	i = 0;
	j = 0;
	len = get_len(*str);
	temp = (char *)ft_calloc(1, len + 2);
	if (!temp)
		return (free(*str), NULL);
	while (*str && (*str)[i])
	{
		temp[j++] = (*str)[i++];
	}
	temp[j] = c;
	temp[++j] = 0;
	if (*str)
		free(*str);
	return (temp);
}

int	is_white_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	else
		return (0);
}

int	is_redirect(char c)
{
	if (c == '<' || c == '>')
		return (1);
	else
		return (0);
}
