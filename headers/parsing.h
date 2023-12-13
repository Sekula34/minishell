/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:56:52 by wvan-der          #+#    #+#             */
/*   Updated: 2023/12/13 12:09:31 by wvan-der         ###   ########.fr       */
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
int		expand_var_1(t_tokens *tok, t_vars *head_ex, int *i, char **res);
char	*get_value_var(t_vars *head_ex, char *key);
char	*check_key(t_tokens *tok);
int		put_value(t_tokens *tok, t_vars *head_ex, char *line, char **res);
char	*first_expand(t_tokens *tok, t_vars *head_ex, char *line);
int		go_back_to_check_redirect(t_tokens *tok, char *line, int i);
int		append_value(char **res, char *value);
int		set_start_end(t_tokens *tok, char *line, int i);
char	**make_token(t_tokens *tok, char *line);
int		copy_text(t_tokens *tok, char *line, int *i, int a);
void	tokenize_redirect(t_tokens *tok, char *line, int *i, int *a);
int		count_token(t_tokens *tok, char *line);
void	move_counter(t_tokens *tok);
char	**last_expand(t_tokens *tok, t_vars *head_ex);
int		put_value_2d(t_tokens *tok, t_vars *head_ex, char *line, char **res, int j);
int		check_heredoc(char **tokens, int j);
int		classify_redirect(t_tokens *tok, int j);
int		classifiying_tokens(t_tokens *tok);
int		is_redirect(char c);

#endif