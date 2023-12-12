/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_expand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:53:01 by wvan-der          #+#    #+#             */
/*   Updated: 2023/12/12 18:14:56 by wvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishel.h"

int	set_start_end(t_tokens *tok, char *line, int i)
{
	i++;
	tok->start = i;
	while (line[i] && valid_char(line[i]))
	{
		i++;
	}
	tok->end = i - 1;
	if (tok->end < tok->start)
	{
		tok->end++;
	}
	return (1);
}

int	append_value(char **res, char *value)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
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
	while (i > 0 && ((line[i] != ' ' && line[i] != '\t')
			|| tok->isq == 1 || tok->idq == 1))
	{
		set_quotation(tok, line[i]);
		if (line[i] == '<' || line[i] == '>')
			return (1);
		i--;
	}
	while (i > 0 && (line[i] == ' ' || line[i] == '\t'))
	{
		set_quotation(tok, line[i]);
		i--;
	}
	if (line[i] == '<' || line[i] == '>')
		return (1);
	else
		return (0);
}

char *get_var_value(t_tokens *tok, t_vars *head_ex, char *line)
{
	t_vars	*element;
	char	*key;
	char	*temp;

	key = ft_substr(line, tok->start, tok->end - tok->start + 1);
	if (!key)
		return (NULL);
	if (!key[0]) //|| key[0] == '\'' || key[0] == '"')
		return (puts("key null"), NULL);
	if (key[0] == '\'' || key[0] == '"')
	{
		puts("äääää");
		temp = ft_substr(key, 1, ft_strlen(key) - 2);
		printf("temp:%s-\n", temp);
		free(key);
		return (temp);
	}
	printf("key:-%s-\n", key);
	puts("?");
/* 	if (key[0] == '\'' || key[0] == '"')
		return ("'"); */
	element = get_element(key, head_ex);
	free(key);
	if (!element)
		return (puts("element null"), NULL);
	return (element->value);
}

int put_value(t_tokens *tok, t_vars *head_ex, char *line, char **res)
{
	char *value;

	value = get_var_value(tok, head_ex, line);
	if (!value)
		return (0);
/* 	if (value[0] == '\'')
		 */
		
	check_value(&value);
	append_value(res, value);
	return (1);
}

char	*check_key(t_tokens *tok)
{
	char *key;

	key = ft_substr(tok->line, tok->start, tok->end - tok->start + 1);
	if (!key)
		return (NULL);


}

char *get_value_var(t_vars *head_ex, char *key)
{
	char *value;

	value = get_element(key, head_ex);

}

int	expand_var_1(t_tokens *tok, t_vars *head_ex, int *i, char **res)
{
	int dollar_index;
	char *key;
	char *value;
	dollar_index = *i;
	set_start_end(tok, tok->line, (*i) + 1);
	key = check_key(tok);
	if (is_quote(key[0]))
		value = key;
	else
		value = get_value(head_ex, key);
	if (value)
	{
		append_value(res, value);
		*i = tok->end;
	}
	else
		(*i)++;
}

char	*first_expand(t_tokens *tok, t_vars *head_ex, char *line)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	res = NULL;
	tok->line = line;
	while (line[i])
	{
		set_quotation(tok, line[i]);
		if (tok->isq == 0 && tok->idq == 0 && line[i] == '$'
			&& go_back_to_check_redirect(tok, line, i) == 0)
		{
			expand_var_1(tok, head_ex, &i, &res);
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