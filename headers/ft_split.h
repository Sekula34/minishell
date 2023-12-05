#ifndef FT_SPLIT_H
#define FT_SPLIT_H

typedef struct s_tokens
{
	int isq;
	int idq;
	int	token_count;
	int redirect_count;
	int flag;
	char **token_array;
	int i;
	int	j;
	int	start;
	int	end;
	int redirect_flag;
	char **tokens
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
char **last_expand(char **tokens);

#endif