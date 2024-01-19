/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rereplace_redirect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:21:18 by wvan-der          #+#    #+#             */
/*   Updated: 2024/01/19 15:31:04 by wvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishel.h"

void	rereplace_redirect(t_tokens *tok)
{
	int	i;
	int	j;

	j = 0;
	while (tok->fin[j])
	{
		i = 0;
		while (tok->fin[j][i])
		{
			if (tok->fin[j][i] == -1)
				tok->fin[j][i] = '<';
			if (tok->fin[j][i] == -2)
				tok->fin[j][i] = '>';
			i++;
		}
		j++;
	}
}
