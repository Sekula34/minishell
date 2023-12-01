#include "../../headers/minishel.h"

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


char *first_expand(t_split *split, char *line)
{
	t_expand expand;
	int i = 0;
	int j = 0;
	char *res;

	char *value_a = "hello";
	char *value_b = "world";
	res = NULL;
	init_expand_struct(&expand);
	while (line[i])
	{
		set_quotation(split, line[i]);
		if (split->isq == 0 && split->idq == 0 && line[i] == '$')
		{
			set_start_end(&expand, split, line, &i);
			//getvalue
			append_value(&res, value_a);
		}
		res = ft_join(&res, line[i]);
		i++;
	}
	printf("%s", res);
	return (res);
}

int main()
{
	t_split split;
	init_split_struct(&split);
	first_expand(&split, "test $var \"$var_b \" ivan $a");
}

/* int main(int argc, char **argv, char **envp)
{
	t_vars *vars;
	t_split split;
	vars = NULL;
	env_list_init(&vars, envp);

	env(vars);

} */