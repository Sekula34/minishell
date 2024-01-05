/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:56:52 by wvan-der          #+#    #+#             */
/*   Updated: 2024/01/05 16:11:20 by wvan-der         ###   ########.fr       */
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

int	parsing(t_shell *shell, char *line);

void	init_parsing_structs(t_tokens *tok);
void	init_tok_struct(t_tokens *tok);
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
char classify_redirect(t_tokens *tok, int j);
int	classifiying_tokens(t_tokens *tok, t_cmd **cmd_lst);
int		is_redirect(char c);
char *classify_filename(t_tokens *tok, int *j);

t_redirect	*make_redirect_node(char type, char *file_name);
void	add_redirect_node(t_redirect **lst, t_redirect *new_lst);
t_redirect	*end_of_redirect(t_redirect *lst);
t_cmd *make_cmd_node(char *cmd, t_redirect *redirect_lst, t_cmd *cmd_lst);
void add_cmd_node(t_cmd **lst, t_cmd *new_lst);
void	clear_cmd_lst(t_cmd **head);


int	syntax_check(t_tokens *tok, char *line);

void	init_make_token(int *a, int *i);

void	delete_cmd_element(t_cmd **element_to_delete);
void	clear_redirect_lst(t_redirect **head);
void	delete_redirect_element(t_redirect **element_to_delete);
void	clear_cmd_lst(t_cmd **head);



#endif