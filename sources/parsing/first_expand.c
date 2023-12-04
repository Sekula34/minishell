#include "../../headers/minishel.h"
#include	<string.h>

int	valid_char(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c >= 'A' && c <='Z')
		return (1);
	if (c >= '0' && c <= '9')
		return (1);
	if (c == '_')
		return (1);
	return (0);
}

void	init_expand_struct(t_expand *expand)
{
	expand->start = 0;
	expand->end = 0;
	expand->redirect_flag = 0;
}

void	set_start_end(t_expand *expand, t_split *split, char *line, int *i)
{
	(*i)++;
	expand->start = *i;
	while (line[*i] && valid_char(line[*i]))
	{
		(*i)++;
	}
	expand->end = *i - 1;
}

int append_value(char **res, char *value)
{
	int i = 0;
	int j = 0;
	while (value[i])
	{
		*res = ft_join(res, value[i]);
		if (!*res)
			return (0);
		i++;
	}
	return (1);
}


int	go_back_to_check_redirect(t_split *split, char *line, int i)
{
	while (i >= 0 && ((line[i] != ' ' && line[i] != '\t') || split->isq == 1 || split->idq == 1))
	{
		set_quotation(split, line[i]);
		if (line[i] == '<' || line[i] == '>')
			return (1);
		i--;
	}
	while (i >= 0 && (line[i] == ' ' || line[i] == '\t'))
	{
		set_quotation(split, line[i]);
		i--;
	}
	if (line[i] == '<' || line[i] == '>')
		return (1);
	else
	 	return (0);
}

void check_value(char **value)
{
	int i = 0;

	if (!*value)
		return ;
	while ((*value)[i])
	{
		if ((*value)[i] == '<')
			(*value)[i] = -1;
		else if ((*value)[i] == '>')
			(*value)[i] = -2;
		i++;
	}
}

char *first_expand(t_split *split, char *line)
{
	t_expand expand;
	int i = 0;
	int j = 0;
	char *res;

	char *value = strdup("hello");

	res = NULL;
	init_expand_struct(&expand);
	while (line[i])
	{
		set_quotation(split, line[i]);
		if (split->isq == 0 && split->idq == 0 && line[i] == '$')
		{
			if (go_back_to_check_redirect(split, line, i) == 0)
			{
				set_start_end(&expand, split, line, &i);
				//getvalue
				check_value(&value);
				append_value(&res, value);
			}
			else
			{
				res = ft_join(&res, line[i]);
				i++;
			}
		}
		else
		{
			res = ft_join(&res, line[i]);
			i++;
		}
	}
	printf("%s", res);
	return (res);
}

/* int main(int argc, char **argv, char **envp)
{
	t_split split;
	init_split_struct(&split);


	first_expand(&split, "test    > $a $a$var$a'  '$a $b");
} */

/* int main(int argc, char **argv, char **envp)
{
	t_vars *vars;
	t_split split;
	vars = NULL;
	env_list_init(&vars, envp);

	env(vars);

} */