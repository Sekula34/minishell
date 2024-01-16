#include "../../headers/minishel.h"

int	doing_conversion(t_tokens *tok, int j)
{
	int	i;

	i = 1;
	while (is_redirect(tok->tokens[j][i]))
	{
		if (tok->tokens[j][i] == '<')
			tok->tokens[j][i] = -1;
		if (tok->tokens[j][i] == '>')
			tok->tokens[j][i] = -2;
		i++;
	}
}

int	convert_fake_redirect(t_tokens *tok)
{
	int	j;

	j = 0;
	while (tok->tokens[j])
	{
		if (is_quote(tok->tokens[j][0]) && is_redirect(tok->tokens[j][1]))
			doing_conversion(tok, j);
		j++;
	}
}