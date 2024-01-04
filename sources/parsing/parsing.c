/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:39:08 by wvan-der          #+#    #+#             */
/*   Updated: 2024/01/04 17:09:09 by wvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishel.h"

int	parsing(t_shell *shell, char **envp)
{
	t_tokens tok;
	t_vars *head_ex;
	t_vars *head_env;

	t_cmd	*cmd_lst;
	t_cmd	*temp;

	t_redirect *temp_redirect;

	cmd_lst = NULL;
	temp = cmd_lst;




	head_ex = NULL;
	head_env = NULL;
	env_list_init(&head_ex, envp);
	env_list_init(&head_env, envp);
	export("var=test", &head_ex, &head_env, 1);
	export("a=file.txt", &head_ex, &head_env, 1);
	export("c=>", &head_ex, &head_env, 1);

	export("?=EXIT_CODE", &head_ex, &head_env, 0);

	init_tok_struct(&tok);
	char *line;
	
/* 	if (argc > 1)
		line = argv[1];
	else */
	line = "echo hello";



	// "\"$$$$USER''\"" - segfault
	// "\"$$$$USER'\"" - no token
	// "echo '>>' " - three tokens instead of two

	// "echo $$$$$abc abc";
	
	// "'$assads'" - fixed seg fault but still...
	

	// FIXED  	"echo >>><< abc < def >fuck > you" - broken redirection is one token for some reason
	// FIXED	variable on the first place - valgrind errors
	// FIXED	"echo '|' abc < def >fuck > you" - splitted by pipe (should not)
	
	
	char **lines;
	int a = 0;
	int i;

	if (syntax_check(&tok, line) == 0)
		return (puts("syntax error"), 0);

	lines = split_pipes(&tok, line);
	while (lines[a])
	{
		printf("begin:\n");
		printf("%s\n", lines[a]);
		printf("\n");

		char *line2 = first_expand(&tok, head_ex, lines[a]);
/*		printf("first expand:\n");
		printf("%s\n", line2);
		printf("\n"); */

		//puts("after first expand");

		char **tokens = make_token(&tok, line2);
		i = 0;
		free(line2);

		if (!tokens)
			return (0);

		//printf("tokens:\n");
		while (tokens[i])
		{
			//printf("%d: %s\n", i, tokens[i]);
			//free(tokens[i]);
			i++;
		}
		//free(tokens);
		printf("\n");
		
		i = 0;	
		char **fin = last_expand(&tok, head_ex);
		if (!fin)
			return (0);

		classifiying_tokens(&tok, &cmd_lst);

		i = 0;
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

	i = 0;


	shell->cmd_lst = cmd_lst;



	//PRINT RESULT OF PARSING

	puts("");
	puts("RESULT");
	puts("");


	temp = cmd_lst;
	temp_redirect = temp->redirect_lst;

	while (temp)
	{
		printf("cmd:  %s\n", temp->cmd);
		i = 1;

		while (temp->args && temp->args[i])
		{
			printf("arg%d: %s\n", i, temp->args[i]);
			i++;
		}
		temp_redirect = temp->redirect_lst;
		while (temp_redirect)
		{
			printf("redirect: %c, %s\n", temp_redirect->type, temp_redirect->file_name);
			temp_redirect = temp_redirect->next;
		}
		temp = temp->next;
		puts("");
	}
	i = 0;

	printf("\n");


/* 	printf("head ex\n");
	export(NULL, &head_ex, &head_env); */

/* 	clear_list_env(&head_env);
	clear_list_env(&head_ex);
	clear_cmd_lst(&cmd_lst); */


	return (1);
}