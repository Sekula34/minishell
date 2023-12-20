#include "../../headers/minishel.h"

int check_unclosed_quote(t_tokens *tok, char *line)
{
	int	i;
	int	single_count;
	int	double_count;

	i = 0;
	single_count = 0;
	double_count = 0;
	while (line && line[i])
	{
		set_quotation(tok, line[i]);
		if (check_quotes(tok) == 0)
		{
			if (line[i] == '"')
				double_count++;
			if (line[i] == '\'')
				single_count++;
		}
		i++;
	}
	printf("sqc:%d\n", single_count);
	printf("dqc:%d\n", double_count);
	if (check_quotes(tok) == 1)
		return (puts("!"), 0);
/* 	if (double_count % 2 != 0)
		return (puts("!d"), 0);
	if (single_count % 2 != 0)
		return (puts("!s"), 0); */
	return (1);
}

int	syntax_check(t_tokens *tok, char *line)
{
	reset_struct(tok);
	if (check_unclosed_quote(tok, line) == 0)
		return (0);
}