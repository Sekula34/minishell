#include "../../headers/minishel.h"



//fix values !!!!!!



int main(int argc, char **argv, char **envp)
{
	t_tokens tok;
	t_vars *head_ex;
	t_vars *head_env;

	(void)argc;
	(void)argv;

	head_ex = NULL;
	head_env = NULL;
	env_list_init(&head_ex, envp);
	env_list_init(&head_env, envp);
	export("var=pu pu", &head_ex, &head_env);
	export("a=|", &head_ex, &head_env);
	export("c=>", &head_ex, &head_env);

	init_token_struct(&tok);	
	char *line = "$test";
	// "echo $$$$$abc abc";
	// variable on the first place - valgrind errors
	// "'$assads'" - seg fault
	// "echo '|' abc < def >fuck > you" - splitted by pipe (should not)


	// FIXED   "echo >>><< abc < def >fuck > you" - broken redirection is one token for some reason
	char **lines;
	int a = 0;



/* 
	lines = split_pipes(&tok, line);

	return (1); */


	lines = ft_split(line, '|');
	if (!lines)
		return (1);
	while (lines[a])
	{
		printf("begin:\n");
		printf("%s\n", line);
		printf("\n");

		char *line2 = first_expand(&tok, head_ex, lines[a]);
		printf("first expand:\n");
		printf("%s\n", line2);
		printf("\n");

		char **tokens = make_token(&tok, line2);
		int i = 0;
		free(line2);

		if (!tokens)
			return (0);

		printf("tokens:\n");
		while (tokens[i])
		{
			printf("%d: %s\n", i, tokens[i]);
			//free(tokens[i]);
			i++;
		}
		//free(tokens);
		printf("\n");
		
		i = 0;
		char **fin = last_expand(&tok, head_ex);
		if (!fin)
			return (0);

		//rereplace_redirect(&tok);

		printf("last expand\n");
		while (fin[i])
		{
			printf("%d: %s\n", i,  fin[i]);
			//free(fin[i]);
			i++;
		}
		//free(fin);

		classifiying_tokens(&tok);







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

/* 	printf("head ex\n");
	export(NULL, &head_ex, &head_env); */

	clear_list_env(&head_env);
	clear_list_env(&head_ex);

}
