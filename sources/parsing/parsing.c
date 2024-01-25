/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:39:08 by wvan-der          #+#    #+#             */
/*   Updated: 2024/01/22 11:01:03 by wvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishel.h"

static void	init_parsing_struct(t_parsing *p, t_shell *shell, t_cmd *cmd_lst)
{
	p->lines = NULL;
	p->line2 = NULL;
	p->tokens = NULL;
	p->fin = NULL;
	p->a = 0;
	cmd_lst = NULL;
	shell->cmd_lst = cmd_lst;
}

int	parsing_1st_expand_make_tokens(t_tokens *tok, t_shell *shell, t_parsing *p)
{
	char	*temp;

	if (first_expand(tok, shell->head_ex, p->lines[p->a], p) == 0)
		return (put_error("1st expand err"), parsing_free(NULL, p, 0), 0);
	if (p->line2 == NULL)
	{
		temp = malloc(1);
		if (!temp)
			return (put_error("1st expand err2"), parsing_free(NULL, p, 0), 0);
		temp[0] = 0;
		p->line2 = temp;
	}
	if (make_token(tok, p->line2) == 0)
		return (put_error("make token err"), parsing_free(tok, p, 0), 0);
	convert_fake_redirect(tok);
	return (1);
}

int	parsing_2nd_expand_classify(t_tokens *tok, t_shell *shell, t_parsing *p)
{
	if (last_expand(tok, shell->head_ex) == 0)
		return (free_fin(tok), parsing_free(tok, p, 0), 0);
	if (rm_quotes_from_tokens(tok) == 0)
		return (put_error("rm quotes err"), parsing_free(tok, p, 0), 0);
	if (classifiying_tokens(tok, &shell->cmd_lst) == 0)
		return (parsing_free(tok, p, 0), clear_cmd_lst(&shell->cmd_lst), 0);
	return (1);
}

int	parsing(t_shell *shell, char *line)
{
	t_parsing	p;
	t_tokens	tok;

	if (!line)
		return (put_error("line=NULL"), 0);
	init_parsing_struct(&p, shell, NULL);
	init_tok_struct(&tok);
	if (syntax_check(&tok, line) == 0)
		return (2);
	p.lines = split_pipes(&tok, line);
	if (!p.lines)
		return (parsing_free(NULL, &p, 0), 0);
	while (p.lines[p.a])
	{
		if (parsing_1st_expand_make_tokens(&tok, shell, &p) == 0)
			return (0);
		if (parsing_2nd_expand_classify(&tok, shell, &p) == 0)
			return (0);
		p.a++;
		parsing_free(&tok, &p, 1);
	}
	parsing_free(NULL, &p, 2);
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
	//		printf("redirect: %c, %s\n",
				// temp_redirect->type, temp_redirect->file_name);
	// 		temp_redirect = temp_redirect->next;
	// 	}
	// 	temp = temp->next;
	// 	puts("");
	// }s
	// i = 0;
	//puts("after parsing\n");
