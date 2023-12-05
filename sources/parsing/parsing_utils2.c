/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:01:46 by wvan-der          #+#    #+#             */
/*   Updated: 2023/12/05 14:19:21 by wvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishel.h"

void	init_token_struct(t_tokens *tok)
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