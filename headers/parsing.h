/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:56:52 by wvan-der          #+#    #+#             */
/*   Updated: 2023/12/12 18:18:20 by wvan-der         ###   ########.fr       */
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
	char	**tokens;
	char	**fin;
	int		token_amount;
	char	*line;
	char	*key;
	char	*value;
	int		tok_i;
}	t_tokens;

void	init_parsing_struct(t_tokens *tok);
char	**split_pipes(t_tokens *tok, char *input);
int		check_quotes(t_tokens *tok);
void	init_parsing_struct(t_tokens *tok);
int		is_quote(char c);
int		valid_char(char c);
char	*ft_join(char **str, char c);
void	set_quotation(t_tokens *tok, char c);
void	check_value(char **value);
void	reset_struct(t_tokens *tok);
int		is_white_space(char c);

#endif