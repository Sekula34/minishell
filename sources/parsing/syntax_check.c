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
	if (tok->isq == 1)
		return (ft_printf("syntax error near unexpected token `''\n"), 0);
	if (tok->idq == 1)
		return (ft_printf("syntax error near unexpected token `\"'\n"), 0);
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
				return (ft_printf("syntax error near unexpected token `|'\n"), 0);
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
	return (ft_printf("syntax error near unexpected token `|'\n"), 0);
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

static int redirect_left(int *l_count, int *r_count)
{
	(*l_count)++;
	if (*l_count == 3)
		return (ft_printf("syntax error near unexpected token `<'\n"), 0);
	if (*r_count != 0)
		return (ft_printf("syntax error near unexpected token `<'\n"), 0);
	return (1);
}

static int redirect_right(int *r_count, int *l_count)
{
	(*r_count)++;
	if (*r_count == 3)
		return (ft_putstr_fd("syntax error near unexpected token `>'\n", 2), 0);
	if (*l_count != 0)
		return (ft_printf("syntax error near unexpected token `>'\n"), 0);
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
		if (check_quotes(tok) == 0 && line[i] == '<'
			&& redirect_left(&l_count, &r_count) == 0)
			return (0);
		if (check_quotes(tok) == 0 && line[i] == '>'
			&& redirect_right(&r_count, &l_count) == 0)
			return (0);
		if (line[i] != ' ' && line[i] != '\t' && is_redirect(line[i]) == 0)
		{
			l_count = 0;
			r_count = 0;
		}
		i++;
	}
	return (1);
}


int	syntax_check(t_tokens *tok, char *line)
{
	reset_struct(tok);
	if (check_unclosed_quote(tok, line) == 0)
		return (0);
	if (check_pipes(tok, line) == 0)
		return (0);
	if (check_amount_redirect(tok, line) == 0)
		return (0);
	if (check_redirect(tok, line) == 0)
		return (0);

	return (1);
}

