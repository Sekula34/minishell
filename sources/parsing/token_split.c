#include "../../headers/minishel.h"
#include <stdio.h>

void	ft_free(char ***res, int a)
{
	while (a >= 0)
	{
		free((*res)[a]);
		a--;
	}
	free(*res);
}

char	*sub_str(char *str, int start, int end)
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
}

void	init_split_struct(t_split *split)
{
	split->isq = 0;
	split->idq = 0;
	split->word_count = 0;
	split->split = NULL;
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

char **realloc_array(char ***array, int a)
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
}

char **make_token(char *line)
{
	t_split split;
	char **res;
	int i = 0;
	int j = 0;
	int a = 0;
	int redirect_count = 0;
	init_split_struct(&split);
	res = (char **)ft_calloc(10, sizeof(char *));
	if (!res)
		return (NULL);
	while (line[i])
	{
		while (line[i] && is_white_space(line[i]) == 1)
			i++;
		while (line[i] && (is_white_space(line[i]) == 0 || split.isq == 1 || split.idq == 1) && is_redirect(line[i]) == 0)
		{
			set_quotation(&split, line[i]);
			res[a] = ft_join(&(res[a]), line[i]);
			i++;
		}
		if (res[a] && split.isq == 0 && split.idq == 0)
		{
			//realloc_array(&res, ++a);
			a++;
		}
		while (line[i] && is_redirect(line[i]))
		{
			res[a] = ft_join(&(res[a]), line[i]);
			redirect_count++;
			if (redirect_count == 2)
			{
				//realloc_array(&res, ++a);
				a++;
				redirect_count = 0;
			}
			i++;
		}
		if (res[a] && split.isq == 0 && split.idq == 0)
		{
			//realloc_array(&res, ++a);
			a++;
		}
	}
	return (res);
}

int main()
{
	char **res;
	char *line = "echo \"hello world\">file";

	res = make_token(line);
	int a = 0;
	while (res && res[a])
	{
		printf("%d: %s\n", a, res[a]);
		free(res[a]);
		a++;
	}
	if (res)
		free(res);

}
