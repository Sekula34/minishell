#ifndef TOKEN_SPLIT_H
#define TOKEN_SPLIT_H

typedef struct s_tokens
{
	int isq;
	int idq;
	int	tok_i;
	int redirect_count;
	int flag;
	int i;
	int	j;
	int	start;
	int	end;
	int redirect_flag;
	char **tokens;
	char **fin_tok;
	int token_amount;
}	t_tokens;

void	init_split_struct(t_tokens *tokens);
void	set_quotation(t_tokens *tokens, char c);
//void	ft_word_count(t_split *split, char *line);
char	*sub_str(char *str, int start, int end);
int		get_len(char *str);
char 	*ft_join(char **str, char c);
void	set_start_end(t_tokens *tokens, char *line, int *i);
void	check_value(char **value);
int		append_value(char **res, char *value);
void	init_expand_struct(t_tokens *tokens);
int		valid_char(char c);
char **last_expand(t_tokens *tok);
void	init_token_struct(t_tokens *tok);
void	reset_struct(t_tokens *tok);
int	is_white_space(char c);
int is_redirect(char c);
char *first_expand(t_tokens *tok, char *line);
char **make_token(t_tokens *tok, char *line);

#endif