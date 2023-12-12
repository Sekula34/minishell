/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:56:52 by wvan-der          #+#    #+#             */
/*   Updated: 2023/12/12 12:55:27 by wvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_SPLIT_H
# define TOKEN_SPLIT_H

#include "data_types.h"

typedef struct s_tokens
{
	int		isq;
	int		idq;
	int		redirect_count;
	int		flag;
	int		i;
	int		j;
	int		start;
	int		end;
	int		redirect_flag;
	char	**toks;
	char	**fin;
	int		token_amount;
}	t_tokens;

void	init_parsing_struct(t_tokens *tok);
char	**split_pipes(t_tokens *tok, char *input);


#endif