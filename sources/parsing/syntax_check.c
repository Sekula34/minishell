	#include "../../headers/minishel.h"

int check_unclosed_quote(t_tokens *tok, char *line)
{
	int	i;
	int	single_count;
	int	double_count;

	i = 0;
	single_count = 0;
	double_count = 0;
	while (line && line[i])
	{
		set_quotation(tok, line[i]);
		if (check_quotes(tok) == 0)
		{
			if (line[i] == '"')
				double_count++;
			if (line[i] == '\'')
				single_count++;
		}
		i++;
	}
/* 	printf("sqc:%d\n", single_count);
	printf("dqc:%d\n", double_count); */
	if (check_quotes(tok) == 1)
		return (puts("!"), 0);
/* 	if (double_count % 2 != 0)
		return (puts("!d"), 0);
	if (single_count % 2 != 0)
		return (puts("!s"), 0); */
	return (1);
}

int check_pipes(t_tokens *tok, char *line)
{
	int	flag;
	int	i;

	flag = 0;
	i = 0;
	while (line && line[i])
	{
		set_quotation(tok, line[i]);
		if (check_quotes(tok) == 0 && line[i] != '|' && line[i] != ' ')
			flag = 1;
		if (check_quotes(tok) == 0 && line[i] == '|')
		{
			if (flag == 0)
				return (0);
			flag = 0;
		}
		i++;
	}
	return (1);
}

int	check_after_redirect(char *line)
{
	int i;

	i = 0;
	while (line && line[i])
	{
		if (is_redirect(line[i]))
		{
			while (is_redirect(line[i]))
				i++;
			while (line[i] && line[i] != '|')
			{
				if (line[i] != ' ')
					return (1);	
				i++;
			}
		}
		i++;
	}
	return ( 0);
}

int	check_redirect(t_tokens *tok, char *line)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (line && line[i])
	{
		set_quotation(tok, line[i]);
		if (check_quotes(tok) == 0 && is_redirect(line[i]))
			flag = 1;
		i++;
	}
	if (check_quotes(tok) == 0 && flag == 1)
		return (check_after_redirect(line));
	return (1);
}

int check_amount_redirect(t_tokens *tok, char *line)
{
	int	i;
	int	r_count;
	int	l_count;

	i = 0;
	r_count = 0;
	l_count = 0;

	reset_struct(tok);
	while (line && line[i])
	{
		set_quotation(tok, line[i]);
		if (check_quotes(tok) == 0 && line[i] == '<')
		{
			l_count++;
			if (l_count == 3)
				return (0);
			if (r_count != 0)
				return (0);
		}
		if (check_quotes(tok) == 0 && line[i] == '>')
		{
			r_count++;
			if (r_count == 3)
				return (0);
			if (l_count != 0)
				return (0);
		}
		if (line[i] != ' ' && line[i] != '\t' && is_redirect(line[i]) == 0)
		{
			l_count = 0;
			r_count = 0;
		}
		i++;
	}
	return (1);
}

//ADD EXEPTIONS FOR IF SYNTAX ERROR IS IN QUOTES

int	syntax_check(t_tokens *tok, char *line)
{
	reset_struct(tok);
	if (check_unclosed_quote(tok, line) == 0)
		return (puts("quotes"), 0);
	if (check_pipes(tok, line) == 0)
		return (puts("pipes"), 0);
	if (check_redirect(tok, line) == 0)
		return (puts("redirect"), 0);
	if (check_amount_redirect(tok, line) == 0)
		return (puts("to many redirects"), 0);
	return (1);
}

