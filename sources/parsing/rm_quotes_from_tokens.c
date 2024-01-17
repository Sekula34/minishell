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
	//ft_printf("%s\n", temp);
	return(temp);
}

int decide_to_keep(t_tokens *tok, int j)
{
	int i;
	char *res;

	i = 0;
	res = NULL;
	reset_struct(tok);
	while (tok->tokens[j][i])
	{
		set_quotation(tok, tok->tokens[j][i]);
		if (check_quotes(tok) == 0 && is_quote(tok->tokens[j][i]) == 0)
		{
			res = ft_join(&res, tok->tokens[j][i]);
			if (!res)
				return (0);
		}
		else if (tok->isq == 1 && tok->tokens[j][i] != '\'')
		{
			res = ft_join(&res, tok->tokens[j][i]);
			if (!res)
				return (0);
		}
		else if (tok->idq == 1 && tok->tokens[j][i] != '"')
		{
			res = ft_join(&res, tok->tokens[j][i]);
			if (!res)
				return (0);
		}
		i++;
	}
	//ft_printf("res:%s\n", res);
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

// char	*rm_quotes_from_line(char **line)
// {
// 	char *temp;
// 	int	i;
// 	int j;

// 	i = 0;
// 	j = 0;

// 	temp = (char *)malloc(ft_strlen(*line) + 1);
// 	if (!temp)
// 		return (NULL);
	
// 	while ((*line)[i])
// 	{
// 		if (is_quote((*line)[i]) == 0)
// 		{	
// 			temp[j] = (*line)[i];
// 			j++;
// 		}
// 		i++;
// 	}
// 	temp[j] = 0;
// 	free(*line);
// 	return (temp);
// }