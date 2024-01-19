/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:09:26 by wvan-der          #+#    #+#             */
/*   Updated: 2024/01/19 17:15:22 by wvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishel.h"

// void	free_2d_arr(char ***arr)
// {
// 	int	i;

// 	i = 0;
// 	while ((*arr)[i])
// 	{
// 		free((*arr)[i]);
// 		i++;
// 	}
// 	free(*arr);
// }

void	free_tokens(t_tokens *tok)
{
	int	i;

	i = 0;
	if (!tok || !tok->tokens)
		return ;
	while (tok && tok->tokens && tok->tokens[i])
	{
		free(tok->tokens[i]);
		i++;
	}
	free(tok->tokens);
	tok->tokens = NULL;
}

void	free_lines(t_parsing *parsing)
{
	int	i;

	i = 0;
	if (parsing && parsing->lines)
	{
		while (parsing->lines[i])
		{
			free(parsing->lines[i]);
			i++;
		}
		free(parsing->lines);
		parsing->lines = NULL;
	}
}

void	free_fin(t_tokens *tok)
{
	int	i;

	i = 0;
	if (!tok || !tok->fin)
		return ;
	while (tok->fin[i])
	{
		free(tok->fin[i]);
		i++;
	}
	free(tok->fin);
}

void	parsing_free(t_tokens *tok, t_parsing *parsing, int flag)
{
	if (flag == 1)
	{
		free_tokens(tok);
		if (parsing && parsing->line2)
		{
			free(parsing->line2);
			parsing->line2 = NULL;
		}
	}
	else if (flag == 2)
		free_lines(parsing);
	else
	{
		free_tokens(tok);
		free_lines(parsing);
		if (parsing && parsing->line2)
		{
			free(parsing->line2);
			parsing->line2 = NULL;
		}
	}
}
