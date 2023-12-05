#include "../../headers/minishel.h"

void	move_counter(t_tokens *tok)
{
	tok->flag = 0;
	tok->tok_i++;
	tok->redirect_count = 0;
}

int	count_token(t_tokens *tok, char *line)
{
	reset_struct(tok);
	while (line[tok->i])
	{
		while (line[tok->i] && is_white_space(line[tok->i]) == 1)
			tok->i++;
		while (line[tok->i] && (is_white_space(line[tok->i]) == 0 || tok->isq == 1 || tok->idq == 1) && is_redirect(line[tok->i]) == 0)
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
	printf("tokens: %d\n", tok->tok_i);
	return (tok->tok_i);
}
void	tokenize_redirect(t_tokens *tok, char *line)
{
	puts("40");
	printf("%s\n", tok->tokens[tok->tok_i]);
	tok->tokens[tok->tok_i] = ft_join(&(tok->tokens[tok->tok_i]), line[tok->i]);
	tok->redirect_count++;
	puts("42");
	if (tok->redirect_count == 2)
	{
		tok->tok_i++;
		tok->redirect_count = 0;
	}
	tok->i++;
}

char **make_token(t_tokens *tok, char *line)
{
	tok->tokens = (char **)ft_calloc(count_token(tok, line) + 1, sizeof(char *));
	if (!tok->tokens)
		return (NULL);
	reset_struct(tok);
	while (line[tok->i])
	{
		puts("while1");
		while (line[tok->i] && is_white_space(line[tok->i]) == 1)
			tok->i++;
		puts("61");
		while (line[tok->i] && (is_white_space(line[tok->i]) == 0 || tok->isq == 1 || tok->idq == 1) && is_redirect(line[tok->i]) == 0)
		{
			puts("1");
			set_quotation(tok, line[tok->i]);
			puts("1,5");
			tok->tokens[tok->tok_i] = ft_join(&(tok->tokens[tok->tok_i]), line[tok->i++]);
			puts("2");
		}
		if (tok->tokens[tok->tok_i] && tok->isq == 0 && tok->idq == 0)
			tok->tok_i++;
		puts("72");
		while (line[tok->i] && is_redirect(line[tok->i]))
		{
			puts("75");
			tokenize_redirect(tok, line);
			puts("77");
		}
		if (tok->tokens[tok->tok_i] && tok->isq == 0 && tok->idq == 0)
			tok->tok_i++;
	}
	return (puts("ende"), tok->tokens);
}

int main()
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
		a++;
	}

	/* fin = last_expand(res);
	a = 0;
	while (fin && fin[a])
	{
		printf("%d: %s\n", a, fin[a]);
		free(fin[a]);
		a++;
	}
	if (fin)
		free(fin);
 */
}
