#include "../../headers/minishel.h"

int	go_till_end_dq(char *line, int *start, int *end)
{
	*end = *start;
	while (line[*end] && line[*end] != '"')
	{
		(*end)++;
	}
}

int	check_quote(char c, char *line, int *start, int *end)
{
	if (c == '\"')
		return (go_till_end_dq(line, start, end), 1);
	if (c == '"')
		return (2);
	else
	 	return (0);
	
}

char **token_split(t_split *split, char *line)
{
	int start = 0;
	int end = 0;
	int	a = 0;
	int checkres = 0;
	char **res;
	ft_word_count(split, line);

	res = (char **)malloc(sizeof(char *) * split->word_count);
	if (!res)
		return (NULL);
	while (a < split->word_count)
	{
		checkres = 0;
		while (line[start] && line[start] == ' ' && checkres = 0)
			checkres = check_quote(line[start++], line, &start, &end);
		if (checkres)
			continue ;
		end = start;
		while (line[end] && line[end] != ' ')
			check_quote(line[end++], line, &start, &end);
		start = end;
		//
	}

	//while space or not quote
	// start++
	//while echo < you"st<up"id|cat<fuckyou
}

/* char	**ft_split(t_shell *shell, char *line)
{
	t_split	split;
	int	start;
	int end;
	int	a;

	start = 0;
	end = 0;
	a = 0;
	init_split_struct(&split);
	word_count(&split, line);
	split.split = malloc(sizeof(char *) * split.word_count);
	while (a < split.word_count)
	{
		set_quotation(&split, line[start]);
		puts("x");
		while (line[start] && line[start] == ' ')
			set_quotation(&split, line[++start]);
		end = start;
		while (line[end] && line[end] != ' ' && split.isq == 0 && split.idq == 0)
			set_quotation(&split, line[++end]);
		split.split[a] = sub_str(line, start, end - 1);
		a++;
		start = end;
	}
	return (split.split);
} */

void	init_struct(t_shell *shell)
{
	shell->last_exit_code = 0;
	shell->cmd_lst.path = NULL;
	shell->cmd_lst.args = NULL;
	shell->cmd_lst.next = NULL;
	t_redirect redirect_lst;
	redirect_lst.redirect = NULL;
	redirect_lst.next = NULL;
	shell->cmd_lst.redirect_lst = &redirect_lst;
	shell->vars.key = NULL;
	shell->vars.value = NULL;
	shell->vars.next = NULL;

}

//change name of split

int main()
{
	t_shell	shell;
	t_split split;

	init_struct(&shell);
	init_split_struct(&split);
	char **res = token_split(&shell, "hello     \"world hahahha test\"  ivan    ");

	int i = 0;

	while (res && res[i])
	{
		printf("%s\n", res[i]);
		i++;
	}


/* 	t_split	split;
	init_split_struct(&split);
	word_count(&split, "hello    \" world hahahha test \" ivan    ");
	printf("%d", split.word_count); */
}
