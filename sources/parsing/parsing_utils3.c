/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:20:13 by wvan-der          #+#    #+#             */
/*   Updated: 2023/12/13 16:50:03 by wvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishel.h"

int	check_quotes(t_tokens *tok)
{
	if (tok->isq == 1 || tok->idq == 1)
		return (1);
	else
		return (0);
}

int	is_quote(char c)
{
	if (c == '\'')
		return (1);
	if (c == '"')
		return (1);
	else
		return (0);
}
