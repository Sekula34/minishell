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
	while ((*token)[j] && (*token)[j] != '"')
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

int check_tokens_for_quotes(t_tokens *tok, char ***tokensss)
{
	int	i;
	int j;
	char **tokens;

	i = 0;
	j = 0;
	tokens = *tokensss;

/* 	while (tokens[j])
	{
		while (tokens[j][i])
		{
			set_quotation(tok, tokens[j][i]);
			if (to)
			tokens[j] = realloc_token(&tokens[j]);
			if (!tokens[j])
				return (0);
		}
		j++;
	}
	return (1); */




	while (tokens[j])
	{
		if (tokens[j][0] == '"')
		{
			tokens[j] = realloc_token(&tokens[j]);
			if (!tokens[j])
				return (0);
		}
		j++;
	}
	return (1);
}

int rm_quotes_from_tokens(t_tokens *tok, char ***tokenss)
{
	if (check_tokens_for_quotes(tok, tokenss) == 0)
		return (0);
	return (1);
}

char	*rm_quotes_from_line(char **line)
{
	char *temp;
	int	i;
	int j;

	i = 0;
	j = 0;

	temp = (char *)malloc(ft_strlen(*line) + 1);
	if (!temp)
		return (NULL);
	
	while ((*line)[i])
	{
		if (is_quote((*line)[i]) == 0)
		{	
			temp[j] = (*line)[i];
			j++;
		}
		i++;
	}
	temp[j] = 0;
	free(*line);
	return (temp);
}