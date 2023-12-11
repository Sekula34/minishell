/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:07:07 by wvan-der          #+#    #+#             */
/*   Updated: 2023/12/08 15:22:52 by wvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishel.h"

int	split_pipes(char *line)
{
	char **lines;
	
	lines = ft_split(line, '|');
	if (!lines)
		return (0);

	return (1);
}