#include "../../headers/minishel.h"

int main()
{
	t_tokens tok;

	init_token_struct(&tok);	
	char *line = "echo $var > $var$var \"$var\" << $var  $a $a";

	printf("beginn:\n");
	printf("%s\n", line);
	printf("\n");

	char *line2 = first_expand(&tok, line);
	printf("first expand:\n");
	printf("%s\n", line2);
	printf("\n");
	//free(line);

	char **tokens = make_token(&tok, line2);
	int i = 0;
	//free(line2);

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
	char **fin = last_expand(&tok);

	printf("last expand\n");
	while (fin[i])
	{
		printf("%d: %s\n", i,  fin[i]);
		//free(fin[i]);
		i++;
	}
	//free(fin);



}