#include "../../headers/minishel.h"
#include	<string.h>

int	valid_char(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c >= 'A' && c <='Z')
		return (1);
	if (c >= '0' && c <= '9')
		return (1);
	if (c == '_')
		return (1);
	return (0);
}

void	init_expand_struct(t_tokens *tok)
{
	tok->start = 0;
	tok->end = 0;
	tok->redirect_flag = 0;
}

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

void check_value(char **value)
{
	int i = 0;

	if (!*value)
		return ;
	while ((*value)[i])
	{
		if ((*value)[i] == '<')
			(*value)[i] = -1;
		else if ((*value)[i] == '>')
			(*value)[i] = -2;
		i++;
	}
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
	printf("%s", res);
	return (res);
}

int main()
{
	t_tokens tok;

	init_token_struct(&tok);	
	char *line = "echo $var > $var$var \"$var\" << $var  $a $a";

	first_expand(&tok, line);
}