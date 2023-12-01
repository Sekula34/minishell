#ifndef FT_SPLIT_H
#define FT_SPLIT_H

typedef struct s_split
{
	int isq;
	int idq;
	int	token_count;
	int redirect_count;
	int flag;
	char **token_array;
	int i;
}	t_split;


void	init_split_struct(t_split *split);
void	set_quotation(t_split *split, char c);
void	ft_word_count(t_split *split, char *line);
char	*sub_str(char *str, int start, int end);

#endif