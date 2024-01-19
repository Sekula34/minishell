#include "../../headers/minishel.h"

char *realloc_token(char **token)
{
	char *temp;
	int	len;
	int	i;
	int j;


	len = ft_strlen(*token);
	i = 0;
	j = 1;
	temp = (char *)malloc(len - 1);
	if (!temp)
		return (free(*token), NULL);
	while ((*token)[j] && j < len - 1)
	{
		temp[i] = (*token)[j];
		i++;
		j++;
	}
	temp[i] = 0;
	free(*token);
	return(temp);
}

int decide_to_keep(t_tokens *tok, int j)
{
	int i;
	char *res;

	i = 0;
	res = ft_strdup(0);
	if (!res)
		return (0);
	reset_struct(tok);
	while (tok->tokens[j][i])
	{
		set_quotation(tok, tok->tokens[j][i]);
		if (check_quotes(tok) == 0 && is_quote(tok->tokens[j][i]) == 0)
			res = ft_join(&res, tok->tokens[j][i]);
		else if (tok->isq == 1 && tok->tokens[j][i] != '\'')
			res = ft_join(&res, tok->tokens[j][i]);
		else if (tok->idq == 1 && tok->tokens[j][i] != '"')
			res = ft_join(&res, tok->tokens[j][i]);
		if (!res)
			return (0);
		i++;
	}
	free(tok->tokens[j]);
	tok->tokens[j] = res;
	return (1);
}

int rm_quotes_from_tokens(t_tokens *tok)
{
	int j;

	j = 0;
	while (tok->tokens[j])
	{
		decide_to_keep(tok, j);
		j++;
	}
	return (1);
}