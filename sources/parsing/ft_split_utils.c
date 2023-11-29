#include "../../headers/minishel.h"

char	*sub_str(char *str, int start, int end)
{
	int		i;
	int		len;
	char	*res;

	i = 0;
	len = end - start + 1;
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	while (start <= end)
	{
		res[i] = str[start];
		i++;
		start++;
	}
	res[i] = 0;
	return (res);
}

void	init_split_struct(t_split *split)
{
	split->isq = 0;
	split->idq = 0;
	split->word_count = 0;
	split->split = NULL;
}

void	set_quotation(t_split *split, char c)
{
	if (c == '"')
	{
		if (split->idq == 0)
		{
			split->idq = 1;
			//puts("in dq");
		}
		else if (split->idq == 1)
		{
			split->idq = 0;
			//puts("out dq");
		}
	}
	if (c == '\'')
	{
		if (split->isq == 0)
		{
			split->isq = 1;
			//puts("in sq");
		}
		else if (split->isq == 1)
		{
			split->isq = 0;
			//puts("out sq");
		}
	}
}

void	ft_word_count(t_split *split, char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		set_quotation(split, line[i]);
		while (line[i] && line[i] == ' ')
		{
			
			//puts("n +++");
			i++;
			set_quotation(split, line[i]);
		}
		if (line[i] && split->isq == 0 && split->idq == 0)
		{
			//puts("count++");
			split->word_count++;
		}
		while (line[i] && line[i] != ' ')
		{
			
			//puts("t +++");
			i++;
			set_quotation(split, line[i]);
		}
	}
}