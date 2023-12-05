#include "../../headers/minishel.h"
#include	<string.h>

void	set_start_end(t_tokens *tok, char *line, int *i)
{
	(*i)++;
	tok->start = *i;
	while (line[*i] && valid_char(line[*i]))
	{
		(*i)++;
	}
	tok->end = *i - 1;
}

int append_value(char **res, char *value)
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


int	go_back_to_check_redirect(t_tokens *tok, char *line, int i)
{
	while (i >= 0 && ((line[i] != ' ' && line[i] != '\t') || tok->isq == 1 || tok->idq == 1))
	{
		set_quotation(tok, line[i]);
		if (line[i] == '<' || line[i] == '>')
			return (1);
		i--;
	}
	while (i >= 0 && (line[i] == ' ' || line[i] == '\t'))
	{
		set_quotation(tok, line[i]);
		i--;
	}
	if (line[i] == '<' || line[i] == '>')
		return (1);
	else
	 	return (0);
}

char *first_expand(t_tokens *tok, char *line)
{
	int i;
	int j ;
	char *res;

	char *value = strdup("hello");

	i = 0;
	j = 0;
	res = NULL;
	while (line[i])
	{
		set_quotation(tok, line[i]);
		if (tok->isq == 0 && tok->idq == 0 && line[i] == '$' && go_back_to_check_redirect(tok, line, i) == 0)
		{
			set_start_end(tok, line, &i);
			//getvalue
			check_value(&value);
			append_value(&res, value);
		}
		else
			res = ft_join(&res, line[i++]);
	}
	return (res);
}

/* int main()
{
	t_tokens tok;

	init_token_struct(&tok);	
	char *line = "echo $var > $var$var \"$var\" << $var  $a $a";

	first_expand(&tok, line);
} */