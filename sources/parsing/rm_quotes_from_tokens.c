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

int decide_to_keep(t_tokens *tok, char ***tokens, int j)
{
	// int i;
	// char *res;

	// i = 0;
	// res = NULL;
	// reset_struct(tok);
	// while (token[i])
	// {
	// 	set_quotation(tok, token[i]);
	// 	if (check_quotes(tok) == 0 && is_quote(token[i]) == 0)
	// 	{
	// 		res = ft_join(&res, token[i]);
	// 		if (!res)
	// 			return (free(token), NULL);
	// 	}
	// 	else if (tok->isq == 1 && token[i] != '\'')
	// 	{
	// 		res = ft_join(&res, token[i]);
	// 		if (!res)
	// 			return (free(token), NULL);
	// 	}
	// 	else if (tok->idq == 1 && token[i] != '"')
	// 	{
	// 		res = ft_join(&res, token[i]);
	// 		if (!res)
	// 			return (free(token), NULL);
	// 	}
	// 	i++;
	// }
	// ft_printf("res:%s\n", res);
	// free(token);
	// return (res);
}

int rm_quotes_from_tokens(t_tokens *tok, char ***tokens)
{
	int j;

	j = 0;
	while ((*tokens)[j])
	{
		// if (decide_to_keep(tok, tokens) == 0)
		// 	return (0);
		// (*tokens)[i] = decide_to_keep(tok, (*tokens)[i]);
		// if (!(*tokens)[i])
		// 	return (0);
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