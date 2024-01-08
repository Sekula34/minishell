/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willem <willem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:39:08 by wvan-der          #+#    #+#             */
/*   Updated: 2024/01/08 17:12:35 by willem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishel.h"

int	parsing(t_shell *shell, char *line)
{
	//puts("begin parsing");
	t_tokens tok;
	t_cmd	*cmd_lst;
	char **lines;
	char *line2;
	char **tokens;
	char **fin;
	int a;
	
	a = 0;

	cmd_lst = NULL;
	lines = NULL;
	line2 = NULL;
	tokens = NULL;
	fin = NULL;
	
	shell->cmd_lst = cmd_lst;

	if (!line)
		return (puts("line=NULL"), 0);
	if (line[0] == 0)
		return (puts("\"\""), 1);

	init_tok_struct(&tok);


	if (syntax_check(&tok, line) == 0)
		return (puts("syntax error"), 2);

	lines = split_pipes(&tok, line);
	if (!lines)
		return (puts("split pipes err"), parsing_free(&lines, &line2, &tokens, &fin), 0);

	while (lines[a])
	{
		line2 = first_expand(&tok, shell->head_ex, lines[a]);
		if (!line2)
			return (puts("first expand err"), parsing_free(&lines, &line2, &tokens, &fin), 0);

		//ft_printf("\nline\n%s\n", line2);


		//line2 = rm_quotes_from_line(&line2);
		if (!line2)
			return (puts("first expand err"), parsing_free(&lines, &line2, &tokens, &fin), 0);

		tokens = make_token(&tok, line2);


		int i = 0;


/* 		puts("tokens");
		
		while (tokens[i])
		{
			printf("%d: %s\n", i, tokens[i]);
			i++;
		} */


		if (!tokens)
			return (puts("make token err"), parsing_free(&lines, &line2, &tokens, &fin), 0);
		
		rm_quotes_from_tokens(&tok, &tokens);




		fin = last_expand(&tok, shell->head_ex);



		i = 0;



/* 		puts("fin");
		while (fin[i])
		{
			printf("%d: %s\n", i, fin[i]);
			i++;
		} */



		if (!fin)
			return (puts("last expand err"), parsing_free(&lines, &line2, &tokens, &fin), 0);

		if (classifiying_tokens(&tok, &shell->cmd_lst) == 0)
			return (puts("last expand err"), parsing_free(&lines, &line2, &tokens, &fin), clear_cmd_lst(&shell->cmd_lst), 0);


		a++;

	}


	parsing_free(&lines, &line2, &tokens, &fin);


	//puts("after parsing\n");
	return (1);
}