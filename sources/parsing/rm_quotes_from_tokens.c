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

int check_tokens_for_quotes(char ***tok)
{
	int	i;
	int j;
	char **tokens;

	i = 0;
	j = 0;
	tokens = *tok;

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

int rm_quotes_from_tokens(char ***tok)
{
	if (check_tokens_for_quotes(tok) == 0)
		return (0);
	return (1);
}
