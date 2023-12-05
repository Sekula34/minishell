#include "../../headers/minishel.h"
#include <stdio.h>

/* void	ft_free(char ***res, int a)
{
	while (a >= 0)
	{
		free((*res)[a]);
		a--;
	}
	free(*res);
} */

/* char	*sub_str(char *str, int start, int end)
{
	int		i;
	int		len;
	char	*res;

	i = 0;
	len = end - start + 1;
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	while (start <= end)
	{
		res[i] = str[start];
		i++;
		start++;
	}
	res[i] = 0;
	return (res);
} */

void	init_split_struct(t_split *split)
{
	split->isq = 0;
	split->idq = 0;
	split->token_count = 0;
	split->redirect_count = 0;
	split->flag = 0;
	split->i = 0;
	split->token_array = NULL;
}
void	reset_split_struct(t_split *split)
{
	split->isq = 0;
	split->idq = 0;
	split->token_count = 0;
	split->redirect_count = 0;
	split->flag = 0;
	split->i = 0;
}

void	set_quotation(t_split *split, char c)
{
	if (c == '"')
	{
		if (split->idq == 0)
		{
			split->idq = 1;
		}
		else if (split->idq == 1)
		{
			split->idq = 0;
		}
	}
	if (c == '\'')
	{
		if (split->isq == 0)
		{
			split->isq = 1;
		}
		else if (split->isq == 1)
		{
			split->isq = 0;
		}
	}
}

int is_redirect(char c)
{
	if (c == '<' || c == '>')
		return (1);
	else
	 	return (0);
}
int get_len(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		i++;
	}
	return (i);
}

char *ft_join(char **str, char c)
{
	int i = 0;
	int j = 0;
	int len = get_len(*str);
	char *temp = (char *)malloc(len + 2);
	if (!temp)
		return (NULL);
	while (*str && (*str)[i])
	{
		temp[j++] = (*str)[i++];
	}
	temp[j] = c;
	temp[++j] = 0;
	if (*str)
		free(*str);
	return (temp);
}

int	is_white_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	else
	 	return (0);
}

/* char **realloc_array(char ***array, int a)
{
	char **temp;
	int i = 0;
	int j = 0;

	temp = (char **)ft_calloc(2 + a, sizeof(char *));
	if (!temp)
		return (NULL);
	while (i < a)
	{
		temp[i] = (*array)[i];
		i++;
	}
	temp[i] = 0;
	ft_free(array, 2 + a - 1);
	return(temp);
} */

void	move_counter(t_split *split)
{
	split->flag = 0;
	split->token_count++;
	split->redirect_count = 0;
}

int	count_token(t_split *split, char *line)
{
	init_split_struct(split);
	while (line[split->i])
	{
		while (line[split->i] && is_white_space(line[split->i]) == 1)
			split->i++;
		while (line[split->i] && (is_white_space(line[split->i]) == 0 || split->isq == 1 || split->idq == 1) && is_redirect(line[split->i]) == 0)
		{
			set_quotation(split, line[split->i++]);
			split->flag = 1;
		}
		if (split->flag && split->isq == 0 && split->idq == 0)
			move_counter(split);
		while (line[split->i] && is_redirect(line[split->i]))
		{
			split->flag = 1;
			split->redirect_count++;
			if (split->redirect_count == 2)
				move_counter(split);
			split->i++;
		}
		if (split->flag && split->isq == 0 && split->idq == 0)
			move_counter(split);
	}
	//printf("count: %d\n", split->token_count);
	return (split->token_count);
}

char **make_token(char *line)
{
	t_split split;
	int i;

	i = 0;
	split.token_array = (char **)ft_calloc(count_token(&split, line) + 1, sizeof(char *));
	reset_split_struct(&split);
	if (!split.token_array)
		return (NULL);
	while (line[i])
	{
		while (line[i] && is_white_space(line[i]) == 1)
			i++;
		while (line[i] && (is_white_space(line[i]) == 0 || split.isq == 1 || split.idq == 1) && is_redirect(line[i]) == 0)
		{
			set_quotation(&split, line[i]);
			split.token_array[split.token_count] = ft_join(&(split.token_array[split.token_count]), line[i]);
			i++;
		}
		if (split.token_array[split.token_count] && split.isq == 0 && split.idq == 0)
			split.token_count++;
		while (line[i] && is_redirect(line[i]))
		{
			split.token_array[split.token_count] = ft_join(&(split.token_array[split.token_count]), line[i]);
			split.redirect_count++;
			if (split.redirect_count == 2)
			{
				split.token_count++;
				split.redirect_count = 0;
			}
			i++;
		}
		if (split.token_array[split.token_count] && split.isq == 0 && split.idq == 0)
			split.token_count++;
	}
	return (split.token_array);
}

int main()
{
	char **res;
	char *line = "echo << $a \"hello world\">file.txt";

	res = make_token(line);
	char **fin;
	int a = 0;

	while (res && res[a])
	{
		printf("%d: %s\n", a, res[a]);
		a++;
	}

	fin = last_expand(res);
	a = 0;
	while (fin && fin[a])
	{
		printf("%d: %s\n", a, fin[a]);
		free(fin[a]);
		a++;
	}
	if (fin)
		free(fin);

}
