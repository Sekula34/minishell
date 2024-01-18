/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:39:08 by wvan-der          #+#    #+#             */
/*   Updated: 2024/01/18 18:43:55 by wvan-der         ###   ########.fr       */
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
		return (put_error("line=NULL"), 0);
	if (line[0] == 0)
		return (put_error("\"\""), 1);

	init_tok_struct(&tok);


	if (syntax_check(&tok, line) == 0)
		return (2);


	lines = split_pipes(&tok, line);
	if (!lines)
		return (parsing_free(NULL, &lines, &line2), 0);

	while (lines[a])
	{
		line2 = first_expand(&tok, shell->head_ex, lines[a]);
		if (!line2)
			return (put_error("first expand err"), parsing_free(NULL, &lines, &line2), 0);

		//ft_printf("\nline\n%s\n", line2);

		if (!line2)
			return (put_error("first expand err"), parsing_free(NULL, &lines, &line2), 0);


		// if (shell->cmd_lst->args[0])
		// 	puts("yes");
		if (make_token(&tok, line2) == 0)
			return (put_error("make token err"), parsing_free(&tok, &lines, &line2), 0);

		int i = 0;


		// puts("tokens");
		// while (tok.tokens[i])
		// {
		// 	printf("%d: %s\n", i, tok.tokens[i]);
		// 	i++;
		// }

		convert_fake_redirect(&tok);
		
		
		
		
		if (last_expand(&tok, shell->head_ex) == 0)
			return (put_error("last expand err"), free_fin(&tok), parsing_free(&tok, &lines, &line2), 0);


		i = 0;


		if (rm_quotes_from_tokens(&tok) == 0)
			return (put_error("rm quotes err"), parsing_free(&tok, &lines, &line2), 0);
		


		
		
		// puts("fin");
		// while (tok.tokens[i])
		// {
		// 	printf("%d: %s\n", i, tok.tokens[i]);
		// 	i++;
		// }





		

		if (classifiying_tokens(&tok, &shell->cmd_lst) == 0)
			return (put_error("classifying err"), parsing_free(&tok, &lines, &line2), clear_cmd_lst(&shell->cmd_lst), 0);


		a++;
 
		parsing_free(&tok, NULL, &line2);
		
	}

	parsing_free(NULL, &lines, NULL);
	




	// puts("");
	// puts("RESULT");
	// puts("");

	// t_cmd *temp;
	// t_redirect *temp_redirect;

	// int i;

	// temp = shell->cmd_lst;
	// temp_redirect = temp->redirect_lst;

	// while (temp)
	// {
	// 	printf("cmd:  %s\n", temp->cmd);
	// 	i = 1;

	// 	while (temp->args && temp->args[i])
	// 	{
	// 		printf("arg%d: %s\n", i, temp->args[i]);
	// 		i++;
	// 	}
	// 	temp_redirect = temp->redirect_lst;
	// 	while (temp_redirect)
	// 	{
	// 		printf("redirect: %c, %s\n", temp_redirect->type, temp_redirect->file_name);
	// 		temp_redirect = temp_redirect->next;
	// 	}
	// 	temp = temp->next;
	// 	puts("");
	// }
	// i = 0;


	//puts("after parsing\n");
	return (1);
}
