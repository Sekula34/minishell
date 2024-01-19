/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:39:08 by wvan-der          #+#    #+#             */
/*   Updated: 2024/01/19 17:46:07 by wvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishel.h"

static void	init_parsing_struct(t_parsing *parsing, t_shell *shell, t_cmd *cmd_lst)
{
	parsing->lines = NULL;
	parsing->line2 = NULL;
	parsing->tokens = NULL;
	parsing->fin = NULL;
	parsing->a = 0;
	cmd_lst = NULL;
	shell->cmd_lst = cmd_lst;
}

int	parsing(t_shell *shell, char *line)
{
	t_parsing	parsing;
	t_tokens	tok;
	t_cmd		*cmd_lst;

	if (!line)
		return (put_error("line=NULL"), 0);
	init_parsing_struct(&parsing, shell, cmd_lst);
	init_tok_struct(&tok);
	if (syntax_check(&tok, line) == 0)
		return (2);
	parsing.lines = split_pipes(&tok, line);
	if (!parsing.lines)
		return (parsing_free(NULL, &parsing, 0), 0);
	while (parsing.lines[parsing.a])
	{
		parsing.line2 = first_expand(&tok, shell->head_ex, parsing.lines[parsing.a]);
		if (!parsing.line2)
			return (put_error("first expand err"), parsing_free(NULL, &parsing, 0), 0);
		if (make_token(&tok, parsing.line2) == 0)
			return (put_error("make token err"), parsing_free(&tok, &parsing, 0), 0);
		convert_fake_redirect(&tok);
		if (last_expand(&tok, shell->head_ex) == 0)
			return (put_error("last expand err"), free_fin(&tok), parsing_free(&tok, &parsing, 0), 0);
		if (rm_quotes_from_tokens(&tok) == 0)
			return (put_error("rm quotes err"), parsing_free(&tok, &parsing, 0), 0);
		if (classifiying_tokens(&tok, &shell->cmd_lst) == 0)
			return (put_error("classifying err"), parsing_free(&tok, &parsing, 0), clear_cmd_lst(&shell->cmd_lst), 0);
		parsing.a++;
		parsing_free(&tok, &parsing, 1);
	}
	parsing_free(NULL, &parsing, 2);
	return (1);
}





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
