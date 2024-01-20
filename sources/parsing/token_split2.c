/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_split2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:55:29 by wvan-der          #+#    #+#             */
/*   Updated: 2024/01/19 15:56:24 by wvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishel.h"

void	move_counter(t_tokens *tok)
{
	tok->flag = 0;
	tok->tok_i++;
	tok->token_amount++;
	tok->redirect_count = 0;
}
