#ifndef FT_SPLIT_H
#define FT_SPLIT_H

typedef struct s_split
{
	int isq;
	int idq;
	int	word_count;
}	t_split;

void	init_split_struct(t_split *split);
void	set_quotation(t_split *split, char c);
void	word_count(t_split *split, char *line);

#endif