/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:02:03 by fseles            #+#    #+#             */
/*   Updated: 2023/12/01 19:02:04 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishel.h"

//prints everything in linked list begginig from ex_vars
static void	export_print(t_vars *ex_vars)
{
	while (ex_vars != NULL)
	{
		printf("declare -x ");
		if (pos_of_equal(ex_vars->key) == -1)
			printf ("%s\n", ex_vars->key);
		else if (ex_vars->value == NULL)
			printf("%s%c%c\n", ex_vars->key, '"', '"');
		else
			printf("%s%c%s%c\n", ex_vars->key, '"', ex_vars->value, '"');
		ex_vars = ex_vars->next;
	}
}

//allocates and creates element from string
//example Key=12 creates elements wiht KEY Key= and value 12
//return element if ok or NULL if error happens
static t_vars	*create_element_from_string(char *string)
{
	t_vars	*new_element;
	char	*key;
	char	*value;

	if (set_key(&key, string) == -1)
		return (NULL);
	if (set_value(&value, string) == -1)
		return (free(key), NULL);
	new_element = create_element(key, value);
	if (new_element == NULL)
		return (free(key), free(value), NULL);
	return (new_element);
}

//retunr 0 if everything ok, -1 if something fails
//takes 3 arguments
//first is string to be added in linked list(env and ex_vars)
//if string is NULL just prints everything like export
//string should be in format (ARG=12) or (A=) //will work without equal but 
//
//creates 2 identical elements, one for ex_vars, one for env_vars
//first try to remove variables if exist
int	export(char *string, t_vars **ex_vars, t_vars **env_vars)
{
	t_vars	*new_element_ex;
	t_vars	*new_element_env;

	if (string == NULL)
	{
		list_sort_alpha(*ex_vars);
		export_print(*ex_vars);
	}
	else if (pos_of_equal(string) != -1)
	{
		unset(string, ex_vars, env_vars);
		new_element_ex = create_element_from_string(string);
		if (new_element_ex == NULL)
			return (-1);
		new_element_env = create_element_from_string(string);
		if (new_element_env == NULL)
		{
			delete_element(&new_element_ex);
			return (-1);
		}
		add_element_back(ex_vars, new_element_ex);
		add_element_back(env_vars, new_element_env);
		list_sort_alpha(*ex_vars);
	}
	return (0);
}
