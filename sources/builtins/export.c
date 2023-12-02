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
static void export_print(t_vars *ex_vars)
{
	while (ex_vars != NULL)
	{
		printf("declare -x ");
		printf("%s%c%s%c\n", ex_vars->key, '"', ex_vars->value, '"');
		ex_vars = ex_vars->next;
	}
}
//allocates and creates special element
//special element is just element that is 
//created with string that does not contain =
//or = is also last charater
//example LANG=
//LAANG
//returns new allocated elements or NULL if something fails
static t_vars *special_element_create(char *string)
{
	char *string_eq;
	t_vars *new_element;

	string_eq = ft_strjoin(string, "=NULL");
	if (string_eq == NULL)
	{
		perror("strjoin in special_element_create fails\n");
		return (NULL);
	}
	new_element = create_element(string_eq, NULL);
	if (new_element == NULL)
	{
		perror("create element in special_element_create fails\n");
		free(string_eq);
		return(NULL);
	}
	free(new_element->value);
	new_element->value = NULL;
	free(string_eq);
	return(new_element);
}

//allocates!! and return new t_vars element
//elemnt has values of string which should look like
//LANG=HR
//if string does not contain = or have nothing after equal
//creates special elements that has temporary "NULLLL" that is freed 
//after creation
//if error happend return NULL
static t_vars* export_create(char *string)
{
	int		pos_of_eq;
	t_vars *new_element;

	new_element = NULL;
	if (string == NULL)
		return (NULL);
	pos_of_eq = pos_of_equal(string);
	if (pos_of_eq == -1 || pos_of_eq == (int)(ft_strlen(string) - 1))
	{
		new_element = special_element_create(string);
		if(new_element == NULL)
		{
			perror("Creating new element in export create fails \n");
			return (NULL);
		}
	}
	else
	{
		new_element = create_element(string, NULL);
		if (new_element == NULL)
		{
			perror("Creating new element in export create fails \n");
				return (NULL);
		}
	}
	return (new_element);
}

//function that takes string and ex_vars head
//if string is NULL just print everything in ex_vars
//difference between this in env is that we have declare-x
//if string is not null then creates 2 identical elements 
//one is added in list for export variables, and other is added in list for env variables
//BOTH env and export variables
//if everything is ok return 0, Return -1 if error hapens
int export(char *string, t_vars **ex_vars, t_vars **env_vars)
{
	t_vars *new_element_ex;
	t_vars *new_element_env;

	if(string == NULL)
	{
		list_sort_alpha(*ex_vars);
		export_print(*ex_vars);
	}
	else 
	{
		new_element_ex = export_create(string);
		if(new_element_ex == NULL)
			return (-1);
		new_element_env = export_create(string);
		if(new_element_env == NULL)
			return (-1);
		add_element_back(ex_vars, new_element_ex);
		add_element_back(env_vars, new_element_env);
		list_sort_alpha(*ex_vars);
	}
	return (0);
}
