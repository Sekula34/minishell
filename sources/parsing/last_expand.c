#include "../../headers/minishel.h"
#include <stdlib.h>
#include <string.h>

/* int	check_back_for_heredoc1(t_split *split, char *line, int i)
{
	puts("hehe");
	while (i > 0 && ((line[i] != ' ' && line[i] != '\t') || split->isq == 1 || split->idq == 1))
	{
		set_quotation(split, line[i]);
		if (line[i] == '<' && line[i - 1] == '<')
			return (1);
		i--;
	}
	while (i > 0 && (line[i] == ' ' || line[i] == '\t'))
	{
		set_quotation(split, line[i]);
		i--;
	}
	puts("haha");
	if (line[i] == '<' && line[i - 1] == '<')
		return (1);
	else
	 	return (0);
} */

int check_back_for_heredoc(char **tokens, int j)
{
	if (j > 0)
	{
		if (tokens[j - 1][0] && tokens[j - 1][1])
			return (1);
		else
		 	return (0);
	}
	return (0);
}

void	set_start_end_2d(char *line, int *i)
{
	(*i)++;
	while (line[*i] && valid_char(line[*i]))
	{
		(*i)++;
	}
}

int append_value_2d(char ***res, char *value, int a)
{
	int i = 0;
	int j = 0;
	while (value[i])
	{
		*res[a] = ft_join(res[a], value[i]);
		if (!*res)
			return (0);
		i++;
	}
	return (1);
}

char **last_expand(char **tokens)
{
	t_split split;
	t_expand expand;
	int	i;
	//char **res;
	int	j;

	i = 0;
	j = 0;
	//res = NULL;
	char *value = strdup("hello");
	char **res = malloc(sizeof(char *) * 6);
	init_split_struct(&split);
	init_expand_struct(&expand);
	while(tokens[j])
	{
		while(tokens[j][i])
		{
			if (tokens[j][i] == '$' && check_back_for_heredoc(tokens, j) == 0)
			{
				set_start_end_2d(tokens[j], &i);
				//getvalue
				//check_value(&value);
				append_value_2d(&res, value, j);
			}
			else
			{
				res[j] = NULL;
				res[j] = ft_join(&res[j], tokens[j][i++]);
			}
		}
		j++;
	}	
	//printf("%s\n", res);
	return (res);
}

/* int main()
{
	
} */
