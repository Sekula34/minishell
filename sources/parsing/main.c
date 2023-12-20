#include "../../headers/minishel.h"


//fix values !!!!!!

	

int main(int argc, char **argv, char **envp)
{
	t_tokens tok;
	t_vars *head_ex;
	t_vars *head_env;

	t_cmd	*cmd_lst;
	t_cmd	*temp;

	cmd_lst = NULL;
	temp = cmd_lst;


	(void)argc;
	(void)argv;

	head_ex = NULL;
	head_env = NULL;
	env_list_init(&head_ex, envp);
	env_list_init(&head_env, envp);
	export("var=test", &head_ex, &head_env);
	export("a=file.txt", &head_ex, &head_env);
	export("c=>", &head_ex, &head_env);

	export("?=EXIT_CODE", &head_ex, &head_env);

	init_parsing_struct(&tok);
	char *line = "echo hello -n >file2 | wc -l";

	//aske artem about $$var vs $$$var


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

	lines = split_pipes(&tok, line);
	while (lines[a])
	{
		printf("begin:\n");
		printf("%s\n", lines[a]);
		printf("\n");

		char *line2 = first_expand(&tok, head_ex, lines[a]);
/* 		printf("first expand:\n");
		printf("%s\n", line2);
		printf("\n");

		puts("after first expand"); */

		char **tokens = make_token(&tok, line2);
		i = 0;
		free(line2);

		if (!tokens)
			return (0);

/* 		//printf("tokens:\n");
		while (tokens[i])
		{
			//printf("%d: %s\n", i, tokens[i]);
			//free(tokens[i]);
			i++;
		}
		//free(tokens);
		printf("\n"); */
		
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

		a++;
	}

	i = 0;


	puts("");
	puts("RESULT");
	puts("");



	temp = cmd_lst;

	while (temp)
	{
		printf("cmd:  %s\n", temp->cmd);
		i = 1;

		while (temp->args && temp->args[i])
		{
			printf("arg%d: %s\n", i, temp->args[i]);
			i++;
		}
		while (temp->redirect_lst)
		{
			printf("redirect: %c, %s\n", temp->redirect_lst->type, temp->redirect_lst->file_name);
			temp->redirect_lst = temp->redirect_lst->next;
		}
		temp = temp->next;
		puts("");
	}
	i = 0;

	printf("\n");

/* 	printf("head ex\n");
	export(NULL, &head_ex, &head_env); */

	clear_list_env(&head_env);
	clear_list_env(&head_ex);
	/* clear_cmd_lst(&cmd_lst); */

}
