/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:39:08 by wvan-der          #+#    #+#             */
/*   Updated: 2024/01/05 15:59:18 by wvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishel.h"

int	parsing(t_shell *shell, char *line)
{
	puts("begin parsing\n");
	t_tokens tok;
	t_cmd	*cmd_lst;
	char **lines;
	int a;
	
	a = 0;

	cmd_lst = NULL;
	

	if (!line)
		return (puts("line=NULL"), 1);

	init_tok_struct(&tok);


	if (syntax_check(&tok, line) == 0)
		return (puts("syntax error"), 0);

	lines = split_pipes(&tok, line);
	if (!lines)
		return (puts("split pipes err"), 0);

	while (lines[a])
	{
		char *line2 = first_expand(&tok, shell->head_ex, lines[a]);
		if (!line2)
			return (puts("first expand err"), 0);

		char **tokens = make_token(&tok, line2);
		free(line2);
		if (!tokens)
			return (puts("make token err"), 0);
		
		char **fin = last_expand(&tok, shell->head_ex);
		if (!fin)
			return (puts("last expand err"), 0);

		classifiying_tokens(&tok, &cmd_lst);

		int i = 0;
		while (tokens[i])
		{
			free(tokens[i]);
			i++;
		}
		free(tokens);

		i = 0;
		while (fin[i])
		{
			free(fin[i]);
			i++;
		}
		free(fin);
		free(lines[a]);

		a++;
	}
	free(lines);

	shell->cmd_lst = cmd_lst;

	return (1);
}