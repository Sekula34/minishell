#include "../../headers/minishel.h"
#include <stdlib.h>
#include <string.h>

int check_back_for_heredoc(char **tokens, int j)
{
	if (j > 0)
	{
		if (tokens[j - 1][0] == '<' && tokens[j - 1][1] == '<')
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

int append_value_2d(char **res, char *value, int a)
{
	int i = 0;
	int j = 0;

	while (value[i])
	{
		*res = ft_join(res, value[i]);
		if (!*res)
			return (0);
		i++;
	}
	return (1);
}

char **last_expand(t_tokens *tok)
{
	char *value = strdup("hello");

	int	i;
	int	j;

	j = 0;
	tok->fin_tok = (char **)ft_calloc(tok->token_amount + 1, sizeof(char *));
	reset_struct(tok);
	while(tok->tokens[j])
	{
		i = 0;
		while(tok->tokens[j][i])
		{
			if (tok->tokens[j][i] == '$' && check_back_for_heredoc(tok->tokens, j) == 0)
			{
				set_start_end_2d(tok->tokens[j], &i);
				//getvalue
				//check_value(&value);
				append_value_2d(&tok->fin_tok[j], value, j);
			}
			else
				tok->fin_tok[j] = ft_join(&tok->fin_tok[j], tok->tokens[j][i++]);
		}
		j++;
	}
	tok->fin_tok[j] = 0;
	return (tok->fin_tok);
}

