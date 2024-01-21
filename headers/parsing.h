/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:56:52 by wvan-der          #+#    #+#             */
/*   Updated: 2024/01/21 19:43:26 by wvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "data_types.h"

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
	char	c_flag;
	int		found_arg_flag;
	int		found_cmd_flag;
}	t_tokens;

typedef struct s_parsing
{
	char	**lines;
	char	*line2;
	char	**tokens;
	char	**fin;
	int		a;
}	t_parsing;

int			parsing(t_shell *shell, char *line);
int			put_arg(t_tokens *tok, int *j, t_cmd **cmd_lst);
int			make_arg_arr(t_tokens *tok, t_cmd **cmd_lst);
int			classify(t_tokens *tok, t_cmd **c_lst, int *j, t_redirect **r_lst);
int			check_0_cmd_arg(t_tokens *tok, t_cmd **cmd_lst, t_redirect **r_lst);
int			classifiying_tokens(t_tokens *tok, t_cmd **cmd_lst);
char		classify_redirect(t_tokens *tok, int j);
int			rm_quotes_from_filename(char **filename);
char		*make_filename(t_tokens *tok, int *j);
int			fill_redirect_node(t_tokens *tok, int *j, t_redirect **r_lst);
int			put_cmd(t_tokens *tok, int *j, t_cmd **cmd_lst, t_redirect *r_lst);
int			get_array_size(t_cmd *cmd_lst);
int			realloc_array(t_cmd **cmd_lst, char *arg);
t_cmd		*make_cmd_node(char *cmd, t_redirect *r_lst, t_cmd *cmd_lst);
void		add_cmd_node(t_cmd **lst, t_cmd *new_lst);
void		doing_conversion(t_tokens *tok, int j);
void		convert_fake_redirect(t_tokens *tok);
void		convert_fake_redirect_back(char **str);
int			handle_next_zero_or_dollar_1(t_tokens *tok, int *i, char **res);
int			expand_var_1(t_tokens *tok, t_vars *head_ex, int *i, char **res);
char		*first_expand(t_tokens *tok, t_vars *head_ex, char *line);
int			set_start_end(t_tokens *tok, char *line, int i);
int			append_value(char **res, char *value);
int			go_back_to_check_redirect(t_tokens *tok, char *line, int i);
char		*check_key(t_tokens *tok);
int			get_value_var(t_vars *head_ex, char *key, char **value);
int			case_start_with_quote_single(char **res, t_tokens *tok, int *i);
int			case_start_with_quote_double(char **res, t_tokens *tok, int *i);
int			case_start_with_quote(char **res, t_tokens *tok, int *i);
int			case_invalid_char(char **res, t_tokens *tok, int *i);
int			append_or_not_1(char **res, char **value, int *i, t_tokens *tok);
void		free_2d_arr(char ***arr);
void		free_tokens(t_tokens *tok);
void		free_fin(t_tokens *tok);
void		clear_cmd_lst(t_cmd **head);
void		delete_cmd_element(t_cmd **element_to_delete);
void		clear_redirect_lst(t_redirect **head);
void		delete_redirect_element(t_redirect **element_to_delete);
char		*get_key_heredoc(t_shell *s, int i, char **res, t_tokens *tok_h);
int			expand_var_heredoc(t_shell *s, int *i, char **res, t_tokens *tok_h);
int			expand_var_2(t_tokens *tok, t_vars *head_ex, int *i, int *j);
void		free_tokens_set_fin(t_tokens *tok);
int			last_expand_logic(t_tokens *tok, t_vars *head_ex, int *j);
int			last_expand(t_tokens *tok, t_vars *head_ex);
int			check_heredoc(char **tokens, int j);
char		*get_key_2(t_tokens *tok, int j);
int			case_invalid_c_2(t_tokens *tok, int *j, int *i);
int			handle_next_zero_or_dollar_2(t_tokens *tok, int *i, int *j);
int			append_or_not_2(char **value, t_tokens *tok, int *i, int *j);
void		set_quotation(t_tokens *tok, char c);
int			get_len(char *str);
char		*ft_join(char **str, char c);
int			is_white_space(char c);
int			is_redirect(char c);
void		init_tok_struct(t_tokens *tok);
void		reset_struct(t_tokens *tok);
void		check_value(char **value);
int			valid_char(char c);
void		init_make_token(int *a, int *i);
int			check_quotes(t_tokens *tok);
int			is_quote(char c);
void		put_error(char *str);
t_redirect	*make_redirect_node(char type, char *file_name);
void		add_redirect_node(t_redirect **lst, t_redirect *new_lst);
void		rereplace_redirect(t_tokens *tok);
char		*realloc_token(char **token);
int			decide_to_keep(t_tokens *tok, int j);
int			rm_quotes_from_tokens(t_tokens *tok);
void		ft_free(char ***res, int a);
int			count_pipes(t_tokens *tok, char *input);
char		**split_pipes(t_tokens *tok, char *line);
int			check_redirect(t_tokens *tok, char *line);
int			check_amount_redirect(t_tokens *tok, char *line);
int			syntax_check(t_tokens *tok, char *line);
int			check_unclosed_quote(t_tokens *tok, char *line);
int			check_pipes(t_tokens *tok, char *line);
int			check_after_redirect(char *line, int i);
void		move_counter(t_tokens *tok);
int			count_token(t_tokens *tok, char *line);
int			tokenize_redirect(t_tokens *tok, char *line, int *i, int *a);
int			copy_text(t_tokens *tok, char *line, int *i, int a);
int			make_token_logic(t_tokens *tok, char *line, int *i, int *a);
int			make_token(t_tokens *tok, char *line);
void		parsing_free(t_tokens *tok, t_parsing *parsing, int flag);
int			heredoc_expand(t_shell *shell, char *line, char **final_line);
void		check_g_signal(t_shell *shell);
void		setting_compare_var(char *line, char *eof, int *compare);

#endif