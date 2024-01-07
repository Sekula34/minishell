/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willem <willem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:58:30 by wvan-der          #+#    #+#             */
/*   Updated: 2024/01/07 23:43:09 by willem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishel.h"

void	move_counter(t_tokens *tok)
{
	tok->flag = 0;
	tok->tok_i++;
	tok->token_amount++;
	tok->redirect_count = 0;
}

int	count_token(t_tokens *tok, char *line)
{
	reset_struct(tok);
	while (line[tok->i])
	{
		while (line[tok->i] && is_white_space(line[tok->i]) == 1)
			tok->i++;
		while (line[tok->i] && (is_white_space(line[tok->i]) == 0
				|| check_quotes(tok)) && is_redirect(line[tok->i]) == 0)
		{
			set_quotation(tok, line[tok->i++]);
			tok->flag = 1;
		}
		if (tok->flag && tok->isq == 0 && tok->idq == 0)
			move_counter(tok);
		while (line[tok->i] && is_redirect(line[tok->i]))
		{
			tok->flag = 1;
			tok->redirect_count++;
			if (tok->redirect_count == 2)
				move_counter(tok);
			tok->i++;
		}
		if (tok->flag && tok->isq == 0 && tok->idq == 0)
			move_counter(tok);
	}
	return (tok->tok_i);
}

void	tokenize_redirect(t_tokens *tok, char *line, int *i, int *a)
{
	tok->redirect_count++;
	//printf("redirect count%d\n", tok->redirect_count);
	tok->tokens[*a] = ft_join(&(tok->tokens[*a]), line[*i]);
	if (tok->redirect_count == 2 && is_redirect(line[*i + 1]) && check_quotes(tok) == 0)
	{
		(*a)++;
		//tok->tok_i++;
		tok->redirect_count = 0;
	}
	if (is_redirect(line[*i + 1]) == 0)
		tok->redirect_count = 0;
	(*i)++;
}

int	copy_text(t_tokens *tok, char *line, int *i, int a)
{
	set_quotation(tok, line[*i]);
	tok->tokens[a] = ft_join(&(tok->tokens[a]), line[*i]);
	(*i)++;
	return (1);
}

char	**make_token(t_tokens *tok, char *line)
{
	int		i;
	int		a;

	if (!line)
		return (NULL);
	init_make_token(&a, &i);
	tok->tokens = ft_calloc(count_token(tok, line) + 1, sizeof(char *));
	if (!tok->tokens)
		return (NULL);
	reset_struct(tok);
	while (line[i])
	{
		while (line[i] && is_white_space(line[i]) == 1)
			i++;
		while (line[i] && (is_white_space(line[i]) == 0
				|| check_quotes(tok)) && is_redirect(line[i]) == 0)
			copy_text(tok, line, &i, a);
		if (tok->tokens[a] && tok->isq == 0 && tok->idq == 0)
			a++;
		while (line[i] && is_redirect(line[i]))
			tokenize_redirect(tok, line, &i, &a);
		if (tok->tokens[a] && tok->isq == 0 && tok->idq == 0)
			a++;
	}
	tok->tokens[a] = 0;
	return (tok->tokens);
}

/* int main()
{
	t_tokens tok;

	init_token_struct(&tok);
	char **res;
	char *line = "echo << $a \"hello $a world\">file.txt";

	res = make_token(&tok, line);
	char **fin;
	int a = 0;

	while (res && res[a])
	{
		printf("%d: %s\n", a, res[a]);
		free(res[a]);
		a++;
	}
	free(res);

	fin = last_expand(res);
	a = 0;
	while (fin && fin[a])
	{
		printf("%d: %s\n", a, fin[a]);
		free(fin[a]);
		a++;
	}
	if (fin)
		free(fin);
 
} */
